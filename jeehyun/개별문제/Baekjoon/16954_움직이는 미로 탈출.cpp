/*
 * 그래프
 * 16954 움직이는 미로 탈출
 */

#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;

char map[9][9];
bool visited[9][9];

int dx[] = { 0, -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[] = { 0, 0, 0, -1, 1, -1, 1, -1, 1 };

queue<pair<int, int>> wall;

bool check(int x, int y)
{
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

void moveWall()
{
	int size = wall.size();
	while (size--) {
		int x = wall.front().first;
		int y = wall.front().second;
		wall.pop();

		map[x][y] = '.';

		if (check(x + 1, y)) {
			map[x + 1][y] = '#';
			wall.push({ x + 1, y });
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 8; i++) cin >> map[i];

	for (int i = 7; i >= 0; i--) {
		for (int j = 0; j < 8; j++) {
			if (map[i][j] == '#')
				wall.push({i, j});
		}
	}

	queue<pair<int, int>> q;
	q.push({ 7, 0 });
	visited[7][0] = true;

	while (!q.empty()) {
		// 벽의 위치가 바뀌기 때문에 visited 초기화해서 다시 체크
		memset(visited, false, sizeof(visited));
		int size = q.size();
		while (size--) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (x == 0 && y == 7) {
				cout << 1;
				return 0;
			}

			if (map[x][y] == '#') continue;

			// 인접한 칸으로 이동
			for (int i = 0; i < 9; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (!check(nx, ny) || visited[nx][ny] || map[nx][ny] == '#') continue;
				
				visited[nx][ny] = true;
				q.push({nx, ny});
			}
		}

		// 벽을 아래로 이동
		moveWall();
	}
	cout << 0;
	return 0;
}