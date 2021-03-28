using namespace std;
#include <iostream>

int n, m;
int board[500][500], visit[500][500];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int ans = -1;

void go(int x, int y, int sum, int cnt) {
	if (cnt == 4) {
		if (ans < sum) ans = sum;
		return;
	}
	if (x<0 || x>=n || y<0 || y>=m) return;
	if (visit[x][y] == true) return;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		go(x + direction[i][0], y + direction[i][1], sum + board[x][y], cnt + 1);
	}
	visit[x][y] = false;
}

void solution() {
	int sum;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			go(i, j, 0, 0);
			if (j + 2 < m) {
				if (i + 1 < n) { //ぬ
					sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i + 1][j + 1];
					if (sum > ans) ans = sum;
				}
				if (i - 1 >= 0) { //で
					sum = board[i][j] + board[i][j + 1] + board[i][j + 2] + board[i - 1][j + 1];
					if (sum > ans) ans = sum;
				}
			}
			if (i + 2 < n) {
				if (j + 1 < m) { //た
					sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j + 1];
					if (sum > ans) ans = sum;
				}
				if (j-1 >= 0) { //っ
					sum = board[i][j] + board[i + 1][j] + board[i + 2][j] + board[i + 1][j - 1];
					if (sum > ans) ans = sum;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	solution();
	cout << ans << '\n';
}