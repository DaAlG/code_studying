#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1000000
using namespace std;

int n;
vector<int> prize;
bool visited[MAX][11];

int getPrize()
{
	int num = prize[0];
	for (int i = 1; i < prize.size(); i++) {
		num = num * 10 + prize[i];
	}
	return num;
}

int exchange(int cnt) 
{
	if (cnt >= n) return getPrize();

	int maxPrize = 0;
	for (int i = 0; i < prize.size() - 1; i++) {
		for (int j = i + 1; j < prize.size(); j++) {
			swap(prize[i], prize[j]);

			int num = getPrize();
			if (!visited[num][cnt + 1]) {
				visited[num][cnt + 1] = true;
				maxPrize = max(maxPrize, exchange(cnt + 1));
			}

			swap(prize[j], prize[i]);
		}
	}
	return maxPrize;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int num;
		cin >> num >> n;

		memset(visited, false, sizeof(visited));
		while (num) {
			prize.push_back(num % 10);
			num /= 10;
		}
		reverse(prize.begin(), prize.end());

		cout << "#" << test_case << " " << exchange(0) << "\n";
		prize.clear();
	}

	return 0;
}