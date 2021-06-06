/*
 * 그래프
 * 16933 벽 부수고 이동하기 3
 */

#include <iostream>
#include <queue>
#define MAX 1002
using namespace std;

int n, m, k;
char map[MAX][MAX];
bool visited[MAX][MAX][11][2]; // x, y, 벽 부순 횟수, 낮밤

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

class Info {
public:
	int x;
	int y;
	int dist;
	int cnt;
	int day; // 0은 밤, 1은 낮
	Info(int x, int y, int dist, int cnt, int day) {
		this->x = x;
		this->y = y;
		this->dist = dist;
		this->cnt = cnt;
		this->day = day;
	}
};

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}

	// x, y, 이동 횟수, 벽 부순 횟수, 낮밤
	queue<Info> q;
	q.push(Info(0, 0, 1, 0, 1));
	visited[0][0][0][1] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int dist = q.front().dist;
		int cnt = q.front().cnt;
		int day = q.front().day;
		q.pop();

		if (x == n - 1 && y == m - 1) {
			cout << dist;
			return 0;
		}

		// 이동하지 않고 같은 칸에 머물러있는 경우
		if (!visited[x][y][cnt][!day]) {
			// 방문한 칸의 개수가 하나 늘어나고 낮과 밤이 바뀜
			q.push(Info(x, y, dist + 1, cnt, !day));
		}

		// 상하좌우 이동
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

			// 벽은 낮에만 부술 수 있다
			if (map[nx][ny] == '1' && day) {
				// 벽은 k개까지 부술 수 있다
				if (cnt < k && !visited[nx][ny][cnt + 1][!day]) {
					visited[nx][ny][cnt + 1][!day] = true;
					q.push(Info(nx, ny, dist + 1, cnt + 1, !day));
				}
			}
			else if (map[nx][ny] == '0' && !visited[nx][ny][cnt][!day]) {
				visited[nx][ny][cnt][!day] = true;
				q.push(Info(nx, ny, dist + 1, cnt, !day));
			}
		}
	}
	cout << -1;

	return 0;
}