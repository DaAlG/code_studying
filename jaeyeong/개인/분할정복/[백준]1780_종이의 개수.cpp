using namespace std;
#include <iostream>
#define MAX 2187

int board[MAX][MAX];
int ans[3]; //-1, 0, 1

void solve(int x, int y, int n) {
	if (n == 1) {
		ans[board[x][y] + 1] ++;
		return;
	}
	bool flag1 = true, flag2 = true, flag3 = true;
	for (int i = x; i < x+ n; i++) {
		for (int j = y; j < y + n; j++) {
			if (board[i][j] == -1) {
				flag2 = false;
				flag3 = false;
			}
			else if (board[i][j] == 0) {
				flag1 = false;
				flag3 = false;
			}
			else if (board[i][j] == 1) {
				flag1 = false;
				flag2 = false;
			}
		}
	}
	if (flag1 == true) {
		ans[0] ++;
		return;
	}
	else if (flag2 == true) {
		ans[1] ++;
		return;
	}
	else if (flag3 == true) {
		ans[2] ++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				solve(x + (n / 3) * i, y + (n / 3) * j, n / 3);
			}
		}
	}
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << ans[i] << '\n';
}