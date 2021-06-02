using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int n, m, k;
int board[1000][1000];
int visit[1000][1000][11][2];
int dir[5][2] = { {0,1},{0,-1},{1,0},{-1,0}};
int answer = -1;

bool inRange(int x, int y) {
	return 0 <= x && x <= n && 0 <= y && y <= m;
}

void solve() {
	queue<tuple<int, int, int, int>> q;
	visit [0][0][0][0] = 1;
	q.push(make_tuple(0, 0, 0, 0));
	while (!q.empty()) {
		int x, y, b, night;
		tie(x, y, b, night) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (!inRange(nx, ny)) continue;
			if (board[nx][ny] == 0 && visit[nx][ny][b][1 - night] == 0) {
				visit[nx][ny][b][1 - night] = visit[x][y][b][night] + 1;
				q.push(make_tuple(nx, ny, b, 1 - night));
			}
			if (board[nx][ny] == 1 && night == 0 && b < k && visit[nx][ny][b+1][1 - night] == 0) {
				visit[nx][ny][b + 1][1 - night] = visit[x][y][b][night] + 1;
				q.push(make_tuple(nx, ny, b + 1, 1 - night));
			}
		}
		if (visit[x][y][b][1 - night] == 0) {
			visit[x][y][b][1 - night] = visit[x][y][b][night] + 1;
			q.push(make_tuple(x, y, b, 1 - night));
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j <= k; j++) {
			if (visit[n][m][j][i] != 0) {
				if (answer == -1) answer = visit[n][m][j][i];
				else answer = min(answer, visit[n][m][j][i]);
			}
		}
	}
	cout << answer << '\n';
	return;
}
int main() {
	char x;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}
	n -= 1;
	m -= 1;
	visit[0][0][0][0] = 1;
	solve();
}