using namespace std;
#include <iostream>

int n, m;
int board[50][50]; //-1 black 1 white

int solve(int sx, int sy, int start) {
	int row = start;
	int res = 0;
	for (int i = sx; i < sx + 8; i++) {
		int cur = row;
		row *= -1;
		for (int j = sy; j < sy + 8; j++) {
			if (board[i][j] != cur) res++;
			cur *= -1;
		}
	}
	return res;
}
int main() {
	cin >> n >> m;
	char x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x == 'B') board[i][j] = -1;
			else board[i][j] = 1;
		}
	}
	int ans = 0x3f3f3f3f;
	for (int i = 0; i <= (n - 8); i++) {
		for (int j = 0; j <= (m - 8); j++) {
			ans = min(ans, solve(i, j, -1));
			ans = min(ans, solve(i, j, 1));
		}
	}
	cout << ans << '\n';
}