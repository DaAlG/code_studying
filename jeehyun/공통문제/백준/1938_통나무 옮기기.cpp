#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 50
using namespace std;

int n;
string map[MAX];
bool visited[MAX][MAX][2]; // 수평일 때 0, 수직일 때 1

struct Wood {
	int x;
	int y;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool inRange(int x, int y)
{
	return x >= 0 && y >= 0 && x < n && y < n;
}

bool canRotate(vector<Wood> now)
{
	int k = now[0].x == now[2].x ? 0 : 2;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j ++) {
			int nx = now[i].x + dx[k + j];
			int ny = now[i].y + dy[k + j];

			// nx, ny가 지형을 벗어나거나 움직일 위치에 다른 나무가 있다면 이동할 수 없음
			if (!inRange(nx, ny) || map[nx][ny] == '1')
				return false;
		}
	}

	return true;
}

int bfs(vector<Wood> start, int ver)
{
	queue<pair<vector<Wood>, pair<int, int>>> q;
	q.push({ start, {0, ver} });
	visited[start[1].x][start[1].y][ver] = true;

	while (!q.empty()) {
		vector<Wood> now = q.front().first; // 현재 통나무 위치
		int cnt = q.front().second.first; // 움직인 횟수
		int flag = q.front().second.second; // 0 : 수평, 1 : 수직
		q.pop();

		bool done = true;
		// EEE 위치로 옮겼는지 확인
		for (int i = 0; i < 3; i++) {
			int x = now[i].x;
			int y = now[i].y;
			if (map[x][y] != 'E') {
				done = false;
				break;
			}
		}

		// EEE 위치로 옮겼으므로 이동 그만
		if (done) {
			return cnt;
		}

		// 회전 -> 한 행이나 한 열에만 놓여 있어야 가능
		if (now[0].x == now[2].x || now[0].y == now[2].y) {
			if (canRotate(now) && !visited[now[1].x][now[1].y][!flag]) {
				visited[now[1].x][now[1].y][!flag] = true;

				vector<Wood> next(3);
				if (flag) { // 수직 -> 수평
					next[0] = { now[1].x, now[1].y - 1 };
					next[1] = now[1];
					next[2] = { now[1].x, now[1].y + 1 };
				}
				else { // 수평 -> 수직
					next[0] = { now[1].x - 1, now[1].y };
					next[1] = now[1];
					next[2] = { now[1].x + 1, now[1].y };
				}

				q.push({ next, { cnt + 1, !flag } });
			}
		}

		// 상하좌우 이동
		for (int i = 0; i < 4; i++) {
			vector<Wood> next(3);

			bool impossible = false;
			for (int j = 0; j < 3; j++) {
				int nx = now[j].x + dx[i];
				int ny = now[j].y + dy[i];

				// nx, ny가 지형을 벗어나거나 움직일 위치에 다른 나무가 있다면 이동할 수 없음
				if (!inRange(nx, ny) || map[nx][ny] == '1') {
					impossible = true;
					break;
				}

				next[j].x = nx;
				next[j].y = ny;
			}

			// 통나무를 옮길 수 없는 경우
			if (impossible) continue;
			// 이미 지나갔던 위치인 경우
			if (visited[next[1].x][next[1].y][flag]) continue;

			visited[next[1].x][next[1].y][flag] = true;
			q.push({ next, { cnt + 1, flag } });
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	vector<Wood> start;

	for (int i = 0; i < n; i++) {
		cin >> map[i];
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'B') {
				start.push_back({ i, j });
			}
		}
	}

	// 수평 or 수직
	int ver = start[0].x == start[2].x ? 0 : 1;
	cout << bfs(start, ver);

	return 0;
}