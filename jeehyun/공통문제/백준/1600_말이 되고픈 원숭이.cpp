#include <iostream>
#include <queue>
#define MAX 201
using namespace std;

int k, n, m;
int map[MAX][MAX];
bool visited[MAX][MAX][31];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int hx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int hy[] = { -1, 1, -2, 2, -2, 2, -1, 1 };

bool check(int x, int y)
{
	return x > 0 && x <= n && y > 0 && y <= m;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k >> m >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	queue<pair<pair<int, int>, pair<int, int>>> q;
	q.push({ {1, 1 }, { 0, 0 } });
	visited[1][1][0] = true;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int hmove = q.front().second.second;
		q.pop();

		if (x == n && y == m) {
			cout << cnt;
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (!check(nx, ny) || visited[nx][ny][hmove] || map[nx][ny]) continue;

			visited[nx][ny][hmove] = true;
			q.push({ {nx, ny}, {cnt + 1, hmove} });
		}

		if (hmove < k) {
			for (int i = 0; i < 8; i++) {
				int nx = x + hx[i];
				int ny = y + hy[i];

				if (!check(nx, ny) || visited[nx][ny][hmove + 1] || map[nx][ny]) continue;

				visited[nx][ny][hmove + 1] = true;
				q.push({ {nx, ny}, {cnt + 1, hmove + 1} });
			}
		}
	}
	cout << -1;
	return 0;
}