using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int n, k;
int s, dx, dy;
int board[200][200], visit[200][200];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			if (visit[i][j] == 0) return false;
	}
	return true;
}
void bfs() {
	queue<pair<int, int>> q;
	int cnt = 0, ss=0;

	for (int kk = 1; kk <= k; kk++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == kk) {
					q.push(make_pair(i, j));
					cnt++;
				}
			}
		}
	}

	int nxt = 0;
	while (!q.empty()) {
		cnt--;
		int x, y;
		tie(x, y) = q.front();
		int m = board[x][y];
		visit[x][y] = board[x][y];
		q.pop();
		for (int d = 0; d < 4; d++) {
			int nx = x + dir[d][0];
			int ny = y + dir[d][1];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
			if (board[nx][ny] == 0 && visit[nx][ny] == 0) {
				board[nx][ny] = m;
				q.push(make_pair(nx, ny));
				nxt++;
			}
		}
		if (cnt == 0) {
			cnt = nxt;
			ss++;
		}
		if (ss == s)
			return;
	}
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
			visit[i][j] = board[i][j];
		}
	}

	cin >> s >> dx >> dy;

	bfs();

	cout << board[dx-1][dy-1] << '\n';
}