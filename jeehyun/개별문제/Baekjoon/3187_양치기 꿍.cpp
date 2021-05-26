/*
 * 그래프
 * 3187 양치기 꿍
 */

#include <iostream>
#include <queue>
#define MAX 252
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int sheep, wolf;

void bfs(int stx, int sty)
{
	queue<pair<int, int>> q;
	q.push({ stx, sty });
	visited[stx][sty] = true;

	int w = 0;
	int s = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] || map[nx][ny] == '#') continue;

			if (map[nx][ny] == 'v') w++;
			else if (map[nx][ny] == 'k') s++;

			visited[nx][ny] = true;
			q.push({ nx, ny });
		}
	}

	if (s > w)
		sheep += s;
	else
		wolf += w;
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

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i + 1][j] && map[i][j] == '#') {
				bfs(i, j);
			}
		}
	}
	cout << sheep << ' ' << wolf;

	return 0;
}