/*
 * 그래프
 * 2573 빙산
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 301
using namespace std;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y)
{
	if (visited[x][y]) return;

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] > 0) {
			dfs(nx, ny);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

			if (map[i][j] > 0) {
				q.push({ i, j });
				visited[i][j] = true;
			}
		}
	}

	int year = 0;
	while (!q.empty()) {
		year++;

		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			int cnt = 0;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!visited[nx][ny] && map[nx][ny] == 0)
					cnt++;
			}

			if (map[x][y] - cnt > 0) {
				map[x][y] -= cnt;
				q.push({ x, y });
			}
			else {
				map[x][y] = 0;
			}
		}

		memset(visited, false, sizeof(visited));

		int iceberg = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j] > 0) {
					iceberg++;
					dfs(i, j);
				}
			}
		}

		if (iceberg >= 2) {
			cout << year;
			return 0;
		}
	}
	cout << 0;

	return 0;
}