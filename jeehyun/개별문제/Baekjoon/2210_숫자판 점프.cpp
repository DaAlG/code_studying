/*
 * 브루트포스
 * 2210 숫자판 점프
 */

#include <iostream>
#include <set>
#include <string>
using namespace std;

int n = 5;
int map[5][5];
set<string> num;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(string s, int x, int y)
{
	if (s.size() == 6) {
		if (!num.count(s))
			num.insert(s);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

		dfs(s + to_string(map[nx][ny]), nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dfs(to_string(map[i][j]), i, j);
		}
	}
	
	cout << num.size();
	return 0;
}