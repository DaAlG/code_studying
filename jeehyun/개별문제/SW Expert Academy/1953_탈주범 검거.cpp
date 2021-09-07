#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 50
using namespace std;

int n, m, r, c, L;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
vector<int> tunnel[8] = {
	{ 0, 0, 0, 0 },
	{ 1, 1, 1, 1 },
	{ 1, 0, 1, 0 },
	{ 0, 1, 0, 1 },
	{ 1, 1, 0, 0 },
	{ 0, 1, 1, 0 },
	{ 0, 0, 1, 1 },
	{ 1, 0, 0, 1 }
};

bool isWall(int x, int y)
{
	return x < 0 || x >= n || y < 0 || y >= m;
}

int bfs(int stx, int sty)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int>> q;
	q.push({ stx, sty });
	visited[stx][sty] = true;

	int time = 0;
	int cnt = 0;

	while (!q.empty()) {
		if (time == L)
			break;

		int size = q.size();
		cnt += size;
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			vector<int> d = tunnel[map[x][y]];
			for (int i = 0; i < d.size(); i++) {
				if (d[i] == 0) continue;

				int nx = x + dx[i];
				int ny = y + dy[i];

				if (isWall(nx, ny) || map[nx][ny] == 0 || visited[nx][ny]) continue;

				if (tunnel[map[nx][ny]][(i + 2) % 4]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
		time++;
	}
	return cnt;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m >> r >> c >> L;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[i][j];
			}
		}

		cout << "#" << test_case << " " << bfs(r, c) << "\n";
	}
	return 0;
}