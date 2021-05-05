/*
 * 백트래킹
 * 1189 컴백홈
 */

#include <iostream>
using namespace std;

int n, m, k;
char map[6][6];
bool visited[6][6];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int answer = 0;

void dfs(int x, int y, int dist)
{
	visited[x][y] = true;

	if (x == 0 && y == m - 1) {
		if (dist == k) answer++;
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
		if (visited[nx][ny]) continue;

		if (map[nx][ny] == '.') {
			dfs(nx, ny, dist + 1);
			visited[nx][ny] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	dfs(n - 1, 0, 1);
	cout << answer;
	return 0;
}