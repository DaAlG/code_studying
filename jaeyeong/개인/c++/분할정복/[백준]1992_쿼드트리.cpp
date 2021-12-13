using namespace std;
#include <iostream>

int board[64][64];

void solve(int x, int y, int n) {
	if (n==1) {
		cout << board[x][y];
		return;
	}
	bool black = true, white = true;
	for (int i = x; i < x + n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] == 1) white = false;
			else if (board[i][j] == 0) black = false;
		}
	}
	if (white) cout << 0;
	else if (black) cout << 1;
	else {
		cout << "(";
		solve(x, y, n / 2); //왼쪽 위
		solve(x, y + n / 2, n / 2); //오른쪽 위
		solve(x + n / 2, y, n / 2); //왼쪽 아래
		solve(x + n / 2, y + n / 2, n / 2); //오른쪽 아래
		cout << ")";
	}
}
int main() {
	char x;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}
	solve(0,0,n);
	cout << '\n';
	return 0;
}