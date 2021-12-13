using namespace std;
#include <iostream>
#include <tuple>
#include <queue>

int n;
double perc[4];
int board[29][29];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
double answer;
int arr[15];


bool inRange(int x, int y) {
	return 0 <= x && x < 29 && 0 <= y && y < 29;
}

void solve(int x, int y, int cnt) {
	if (cnt == n) {
		double temp = 1;
		for (int i = 0; i < n; i++)
			temp *= perc[arr[i]];
		answer += temp;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (!inRange(nx, ny)) continue;
		if (board[nx][ny] != 0) continue;
		board[nx][ny] = 1;
		arr[cnt] = i;
		solve(nx, ny, cnt + 1);
		board[nx][ny] = 0;
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < 4; i++) {
		cin >> perc[i];
		perc[i] /= 100;
	}
	board[14][14] = 1;
	solve(14, 14, 0);
	cout.precision(10);
	cout << answer << '\n';
}