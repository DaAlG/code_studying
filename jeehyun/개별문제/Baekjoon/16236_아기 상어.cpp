/*
 * BFS
 * 16236 아기 상어
 */

#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
#define MAX 20
#define INF 0x3f3f3f
using namespace std;

int n;
int map[MAX][MAX];
int d[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int shark = 2; // 아기 상어 크기
int dist; // 아기 상어와 물고기의 거리
int xMin, yMin; // 물고기 위치

void bfs(pair<int, int> start)
{
	queue<pair<int, int>> q;
	q.push(start);
	d[start.first][start.second] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

			// 이미 지나갔거나 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없다
			if (d[nx][ny] != -1 || map[nx][ny] > shark) continue;

			d[nx][ny] = d[x][y] + 1;

			// 먹을 수 있는 물고기라면
			if (map[nx][ny] != 0 && map[nx][ny] < shark) {
				// 거리가 가장 가까운 물고기를 먹는다
				if (dist > d[nx][ny]) {
					xMin = nx;
					yMin = ny;
					dist = d[nx][ny];
				}
				else if (dist == d[nx][ny]) { 
					// 거리가 가장 가까운 물고기가 많다면
					// 가장 위에 있는 물고기
					if (xMin > nx) {
						xMin = nx;
						yMin = ny;
					}
					else if (xMin == nx) {
						// 가장 위에 있는 물고기가 여러마리라면 가장 왼쪽에 있는 물고기
						if (yMin > ny) {
							yMin = ny;
						}
					}
				}
			}

			q.push({nx, ny});
		}
	}
}

int main()
{
	cin >> n;

	pair<int, int> start;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];

			if (map[i][j] == 9) {
				start = {i, j};
				map[i][j] = 0;
			}
		}
	}

	int time = 0;
	int prey = 0;

	while (1) {
		dist = INF;
		xMin = yMin = MAX;
		memset(d, -1, sizeof(d));

		// 먹을 수 있는 물고기를 찾는다
		bfs(start);

		// 더 이상 먹을 수 있는 물고기가 없으므로 엄마 상어에게 도움 요청
		if (xMin == MAX || yMin == MAX)
			break;

		// 이동한 칸만큼 시간 추가
		time += d[xMin][yMin];
		prey++;

		// 자신의 크기와 같은 수의 물고기를 먹을 때마다 크기 증가
		if (prey == shark) {
			shark++;
			prey = 0;
		}

		// 물고기를 먹으면 빈 칸
		map[xMin][yMin] = 0;
		start = { xMin, yMin };
	}

	cout << time;
	return 0;
}