/*
 * 그래프
 * 2589 보물섬
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 52
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int bfs(int stx, int sty)
{
	queue<pair<pair<int, int>, int>> q;
	q.push({ { stx, sty }, 0 });
	visited[stx][sty] = true;

	int maxi = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int d = q.front().second;
		q.pop();

		if (maxi < d) {
			maxi = d;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny] == 'W') continue;

			visited[nx][ny] = true;
			q.push({ { nx, ny }, d + 1 });
		}
	}

	return maxi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				memset(visited, false, sizeof(visited));
				int d = bfs(i, j);
				if (answer < d) {
					answer = d;
				}
			}
		}
	}
	cout << answer;

	return 0;
}