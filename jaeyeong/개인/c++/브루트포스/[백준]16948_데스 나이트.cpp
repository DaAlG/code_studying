using namespace std;
#include <iostream>
#include <queue>

int n;
int sx, sy, dx, dy;
int board[200][200];
int direction[6][2] = { {-2,-1},{-2,1},{0,-2},{0,2},{2,-1},{2,1} };

void bfs() {
	queue <pair<int, int>> q;
	q.push(make_pair(sx, sy));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (board[nx][ny] == 0) {
					board[nx][ny] = board[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
	cin >> n;
	cin >> sx >> sy >> dx >> dy;
	bfs();
	if (board[dx][dy] == 0)
		board[dx][dy] = -1;
	cout << board[dx][dy] << '\n';
}