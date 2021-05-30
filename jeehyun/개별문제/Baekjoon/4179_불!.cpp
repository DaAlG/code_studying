/*
 * 그래프
 * 4179 불!
 */

#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int n, m;
char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	queue<pair<int, int>> q;
	queue<pair<int, int>> fire;
	
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'J') {
				q.push({ i, j });
				map[i][j] = '.';
				visited[i][j] = true;
			}
			else if (map[i][j] == 'F') {
				fire.push({ i, j });
			}
		}
	}

	int answer = 0;

	while (!q.empty()) {
		answer++;

		// 지훈이 이동
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			// 지훈이가 불에 탐...
			if (map[x][y] == 'F')
				continue;

			// 미로의 가장자리에 접한 공간에서 탈출 가능
			if (x == 0 || x == n - 1 || y == 0 || y == m - 1) {
				cout << answer;
				return 0;
			}

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (visited[nx][ny] || map[nx][ny] != '.') continue;

				visited[nx][ny] = true;
				q.push({ nx, ny });
			}
		}

		// 불 확산
		int fsize = fire.size();
		for (int i = 0; i < fsize; i++) {
			int x = fire.front().first;
			int y = fire.front().second;
			fire.pop();

			for (int j = 0; j < 4; j++) {
				int nx = x + dx[j];
				int ny = y + dy[j];

				if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
				if (map[nx][ny] != '.') continue;

				map[nx][ny] = 'F';
				fire.push({ nx, ny });
			}
		}

	}
	cout << "IMPOSSIBLE";

	return 0;
}