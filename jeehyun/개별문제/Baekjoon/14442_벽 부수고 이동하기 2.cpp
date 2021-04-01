/* 그래프
 * 14442 벽 부수고 이동하기 2
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#define MAX 1001
#define INF 1000000000
using namespace std;

int n, m, k;
int map[MAX][MAX];
int visited[MAX][MAX][11];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &map[i][j]);
		}
	}

	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}

	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 0));
	visited[1][1][0] = 1;

	int answer = -1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == n && y == m) {
			answer = visited[x][y][block];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 1 || ny < 1 || nx > n || ny > m) continue;

			// map[nx][ny]가 1이고 벽을 아직 부수지 않은 경우
			if (map[nx][ny] && block < k && !visited[nx][ny][block + 1]) {
				visited[nx][ny][block + 1] = visited[x][y][block] + 1;
				q.push(make_pair(make_pair(nx, ny), block + 1));
			}
			// map[nx][ny]가 0이고 방문하지 않은 경우
			else if (!map[nx][ny] && !visited[nx][ny][block]) {
				visited[nx][ny][block] = visited[x][y][block] + 1;
				q.push(make_pair(make_pair(nx, ny), block));
			}
		}
	}

	cout << answer;
	return 0;
}