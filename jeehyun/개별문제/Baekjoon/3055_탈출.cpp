/* 그래프
 * 3055 탈출
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char map[51][51];
int visited[50][50];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1};

int main()
{
	cin >> n >> m;

	queue<pair<int, int>> q;
	pair<int, int> s;
	pair<int, int> e;

	for (int i = 0; i < n; i++) {
		scanf("%s", &map[i]);
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'S') {
				s.first = i;
				s.second = j;
			}
			else if (map[i][j] == 'D') {
				e.first = i;
				e.second = j;
			}
			else if (map[i][j] == '*') {
				// 물의 위치를 먼저 넣어준다
				q.push(make_pair(i, j));
			}
		}
	}

	// 고슴도치 위치
	q.push(s);

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == e.first && y == e.second)
			break;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (visited[nx][ny] != 0) continue;

			if (map[x][y] == '*') { // 현재 위치가 물이면
				if (map[nx][ny] == '.') {
					map[nx][ny] = '*'; // 다음 위치에 물을 채운다
					q.push(make_pair(nx, ny));
				}
			}
			else { // 현재 위치에 고슴도치가 있으면
				if (map[nx][ny] == '.' || map[nx][ny] == 'D') {
					map[nx][ny] = 'S'; // 다음 위치로 이동
					visited[nx][ny] = visited[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	if (visited[e.first][e.second] == 0)
		cout << "KAKTUS";
	else
		cout << visited[e.first][e.second];

	return 0;
}