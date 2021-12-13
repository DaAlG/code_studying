using namespace std;
#include <iostream>

int n;
int board[10][10];
int answer = -1, total=0;

void checkBishop(int x, int y, int a, int b) {
	int i = -1 * x, j = -x;
	while (x + i < n && y+j<n) {
		if (board[x + i][y + j] == a)
			board[x + i][y + j] = b;
		i++;
		j++;
	}
	i = -1 * x, j = x;
	while (x + i < n && 0<=y+j) {
		if (board[x + i][y + j] == a)
			board[x + i][y + j] = b;
		i++;
		j--;
	}
}

bool possible(int x, int y) {
	int i = -1 * x, j = -x;
	while (x + i < n && y + j < n) {
		if (board[x + i][y + j] <0)
			return false;
		i++;
		j++;
	}
	i = -1 * x, j = x;
	while (x + i < n && 0 <= y + j) {
		if (board[x + i][y + j] <0)
			return false;
		i++;
		j--;
	}
	return true;
}
void solve(int x, int y, int cnt) {
	if (y >= n) {
		x++;
		if (y % 2 == 0) y = 1;
		else y = 0;
	}
	if (x >= n) {
		answer = max(answer, -1 * cnt -1);
		return;
	}
	if (board[x][y] == 1) {
		checkBishop(x, y, 1, cnt);
		solve(x, y + 2, cnt - 1);
		checkBishop(x, y, cnt, 1);
	}
	solve(x, y + 2, cnt);
}
int main() {
	ios_base::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	solve(0,0,-1);
	total = answer;
	answer = -1;
	solve(0, 1, -1);
	total += answer;
	cout << total << '\n';
}