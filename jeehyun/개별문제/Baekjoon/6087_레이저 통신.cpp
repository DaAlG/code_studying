/* BFS
 * 6087 레이저 통신
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <algorithm>
#define MAX 101
using namespace std;

char map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };

int main()
{
	int w, h;
	cin >> w >> h;

	pair<int, int> laser[2];
	int index = 0;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf(" %c", &map[i][j]);

			if (map[i][j] == 'C') {
				laser[index].first = i;
				laser[index++].second = j;
			}
		}
	}

	deque<pair<pair<int, int>, pair<int, int>>> q;
	q.push_front({ laser[0], { 0, -1 } });

	int answer = 10000000;

	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second.first;
		int dir = q.front().second.second;
		q.pop_front();

		visited[x][y] = true;

		if (x == laser[1].first && y == laser[1].second) {
			if (cnt < answer)
				answer = cnt;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int d = dir < 0 ? abs(dir + i + 1) % 4 : abs(dir + i) % 4;
			int nx = x + dx[d];
			int ny = y + dy[d];

			if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;

			if (!visited[nx][ny] && (map[nx][ny] == '.' || map[nx][ny] == 'C')) {
				if (dir >= 0 && (abs(dir - d) == 1 || abs(dir - d) == 3))
					q.push_back({ { nx, ny }, {cnt + 1, d} });
				else
					q.push_front({ {nx, ny}, {cnt, d} });
			}
		}
	}
	cout << answer;

	return 0;
}