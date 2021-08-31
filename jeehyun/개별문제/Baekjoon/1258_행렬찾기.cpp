#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 100
using namespace std;

int n;
int arr[MAX][MAX];
bool visited[MAX][MAX];

bool cmp(pair<int, int> a, pair<int, int> b)
{
	int sa = a.first * a.second;
	int sb = b.first * b.second;

	if (sa == sb)
		return a.first < b.first;
	return sa < sb;
}

pair<int, int> getMatrix(int x, int y)
{
	int r = x;
	int c = y;

	while (r < n && arr[r][y] != 0) r++;
	while (c < n && arr[x][c] != 0) c++;

	r = r - x;
	c = c - y;

	for (int i = x; i < x + r; i++) {
		for (int j = y; j < y + c; j++) {
			visited[i][j] = true;
		}
	}

	return make_pair(r, c);
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}

		vector<pair<int, int>> answer;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 0 && !visited[i][j]) {
					answer.push_back(getMatrix(i, j));
				}
			}
		}
		sort(answer.begin(), answer.end(), cmp);

		cout << "#" << test_case << " " << answer.size() << " ";
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i].first << " " << answer[i].second << " ";
		}
		cout << "\n";
	}
	return 0;
}