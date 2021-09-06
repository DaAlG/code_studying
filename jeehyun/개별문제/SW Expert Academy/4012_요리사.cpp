#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 16
#define INF 1200000
using namespace std;

int n;
int s[MAX][MAX];
bool visited[MAX];

int getSum(vector<int>& arr)
{
	int sum = 0;
	for (int i = 0; i < arr.size(); i++) {
		for (int j = i + 1; j < arr.size(); j++) {
			int a = arr[i];
			int b = arr[j];
			sum += s[a][b] + s[b][a];
		}
	}
	return sum;
}

int cook(int now, int cnt)
{
	if (cnt == n / 2) {
		vector<int> a;
		vector<int> b;
		for (int i = 0; i < n; i++) {
			if (visited[i]) a.push_back(i);
			else b.push_back(i);
		}
		int asum = getSum(a);
		int bsum = getSum(b);
		return abs(asum - bsum);
	}

	int ret = INF;
	for (int i = now + 1; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			ret = min(ret, cook(i, cnt + 1));
			visited[i] = false;
		}
	}
	return ret;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		
		vector<int> material;
		for (int i = 0; i < n; i++) {
			material.push_back(i);
			for (int j = 0; j < n; j++) {
				cin >> s[i][j];
			}
		}
		fill_n(visited, MAX, false);
		cout << "#" << test_case << " " << cook(-1, 0) << "\n";
	}

	return 0;
}