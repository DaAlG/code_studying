/*
 * 그래프
 * 17836 공주님을 구해라!
 */

#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int n, m, T;
int map[MAX][MAX];
bool visited[MAX][MAX][2]; // 0 : 그람 x, 1 : 그람 o

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> T;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> map[i][j];
		}
	}

	// x, y, 거리, 그람 유무
	queue<pair<pair<int, int>, pair<bool, int>>> q;
	q.push({ { 1, 1 }, { 0, 0 } });
	visited[1][1][0] = true; // 시작지점과 도착지점은 항상 0

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		bool gramr = q.front().second.first;
		int d = q.front().second.second;
		q.pop();

		if (x == n && y == m) {
			if (d <= T) cout << d;
			else cout << "Fail";
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

			// 그람을 얻었다
			if (!gramr && map[nx][ny] == 2 && !visited[nx][ny][!gramr]) {
				visited[nx][ny][!gramr] = true;
				q.push({ {nx, ny}, { !gramr, d + 1} });
			}
			// 그람을 얻어서 빈 공간, 마법의 벽을 지날 수 있거나
			// 그람을 얻지 못해서 마법의 벽을 피해야 하는 경우
			else if (!visited[nx][ny][gramr] && (gramr || map[nx][ny] != 1)) {
				visited[nx][ny][gramr] = true;
				q.push({ {nx, ny}, { gramr, d + 1 } });
			}
		}
	}
	cout << "Fail";
	return 0;
}