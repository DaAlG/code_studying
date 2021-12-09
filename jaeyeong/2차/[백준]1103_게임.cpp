using namespace std;
#include <iostream>
#include <cstring>
int n, m;
int board[50][50] = { 0 };
bool visit[50][50] = { false };
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int dp[50][50]; //(x,y)에서 최대로 움직일 수 있는 횟수
int answer = -1;
bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
int dfs(int x, int y) {
	if (!inRange(x, y) || board[x][y] == 0) return 0;
	if (visit[x][y] == true) {
		cout << "-1\n";
		exit(0);
	}
	if (dp[x][y] != -1) return dp[x][y];

	visit[x][y] = true;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + (board[x][y] * direction[i][0]);
		int ny = y + (board[x][y] * direction[i][1]);
		dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
	}
	visit[x][y] = false;
	return dp[x][y];
}
int main() {
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x != 'H')
				board[i][j] = x-'0';
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 0) << '\n';
}