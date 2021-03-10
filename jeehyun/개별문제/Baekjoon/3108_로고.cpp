/* 브루트포스
 * 3108 로고
 */

#include <iostream>
#define MAX 2001
using namespace std;

int N, answer;
int map[MAX][MAX];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int x, int y)
{
	map[x][y] = 2;
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= MAX || ny < 0 || ny >= MAX) continue;

		// 이미 방문했거나 사각형이 없으면 넘어간다
		if (map[nx][ny] == 0 || map[nx][ny] == 2) continue;
		
		dfs(nx, ny);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		// 좌표의 범위는 -500 ~ 500
		// 하지만 배열의 범위는 0부터이므로 좌표에 500을 더해준다
		// 이대로 하면 겹치지 않는 사각형이 겹쳐진 것처럼 입력될 수 있으므로
		// 간격을 넓히기 위해 좌표값을 두배로 늘린다
		x1 = (x1 + 500) * 2;
		y1 = (y1 + 500) * 2;
		x2 = (x2 + 500) * 2;
		y2 = (y2 + 500) * 2;

		for (int j = x1; j <= x2; j++) {
			map[j][y1] = 1;
			map[j][y2] = 1;
		}

		for (int j = y1; j <= y2; j++) {
			map[x1][j] = 1;
			map[x2][j] = 1;
		}
	}

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] == 1) {
				dfs(i, j);
				answer++;
			}
		}
	}

	// 처음에 연필이 내려가있는 상태로 시작하기 때문에
	// 처음 위치에 직사각형이 있을 경우 하나 빼준다
	if (map[1000][1000] == 2)
		answer--;

	cout << answer;
	return 0;
}