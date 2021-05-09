/*
 * 그래프
 * 로봇 청소기
 */

#include <iostream>
#define MAX 51
using namespace std;

int n, m;
int map[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= n || y >= m)
		return false;
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	int x, y, d;
	cin >> x >> y >> d;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 1;
	map[x][y] = 2;
	while (1) {
		bool cleaned = false;

		// 왼쪽 방향에 청소하지 않은 공간이 있는지 확인
		for (int i = 0; i < 4; i++) {
			int nextDir = (d - i + 3) % 4; 
			int nx = x + dx[nextDir];
			int ny = y + dy[nextDir];

			// 아직 청소하지 않은 공간이 있다면 청소
			if (check(nx, ny) && map[nx][ny] == 0) {
				answer++;
				map[nx][ny] = 2;
				x = nx; y = ny;
				d = nextDir;
				cleaned = true;
				break;
			}
		}

		// 왼쪽 방향을 청소했다면 다시 탐색 진행
		if (cleaned) continue;

		// 네 방향 모두 청소 못한 경우
		int nx = x - dx[d];
		int ny = y - dy[d];

		// 뒤가 벽이 아니면 후진
		if (check(nx, ny) && map[nx][ny] != 1) {
			x = nx; y = ny;
		}
		else { // 벽이면 작동을 멈춘다
			break;
		}
	}
	cout << answer;

	return 0;
}