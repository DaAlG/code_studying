/*
 * 그래프
 * 17086 아기 상어 2
 */

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int map[50][50];
bool visited[50][50];

int dx[] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, -1, 1, -1, 1, -1, 1 };

bool check(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int bfs(int stx, int sty)
{
	memset(visited, false, sizeof(visited));
	queue<pair<pair<int, int>, int>> q;
	q.push({ {stx, sty}, 0 });
	visited[stx][sty] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (map[x][y] == 1) {
			return cnt;
		}

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check(nx, ny) || visited[nx][ny]) continue;

			visited[nx][ny] = true;
			q.push({ {nx, ny}, cnt + 1 });
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				answer = max(answer, bfs(i, j));
			}
		}
	}
	cout << answer;
	return 0;
}