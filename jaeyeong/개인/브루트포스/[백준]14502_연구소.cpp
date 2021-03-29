using namespace std;
#include <iostream>
#include <queue>

int n, m;
int board[8][8], board2[8][8];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int bfs() {
	queue<pair<int, int>> q;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board2[i][j] = board[i][j];
			if (board2[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board2[nx][ny] == 0) {
					board2[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board2[i][j] == 0) {
				cnt++;
			}
		}
	}
	return cnt;
}


int main() {
	int ans = -1, temp;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}

	for (int ax = 0; ax < n; ax++) {
		for (int ay = 0; ay < m; ay++) {
			if (board[ax][ay] != 0) continue;
			for (int bx = 0; bx < n; bx++) {
				for (int by = 0; by < m; by++) {
					if (board[bx][by] != 0) continue;
					for (int cx = 0; cx < n; cx++) {
						for (int cy = 0; cy < m; cy++) {
							if (board[cx][cy] != 0)  continue;
							if (ax == bx && ay == by) continue;
							if (ax == cx && ay == cy) continue;
							if (bx == cx && by == cy) continue;
							board[ax][ay] = 1;
							board[bx][by] = 1;
							board[cx][cy] = 1;
							temp = bfs();
							ans = temp > ans ? temp : ans;
							board[ax][ay] = 0;
							board[bx][by] = 0;
							board[cx][cy] = 0;
						}
					}


				}
			}
		}
	}

	cout << ans << '\n';
}
