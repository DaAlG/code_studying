using namespace std;
#include <iostream>
#include <cstring>

//dir: 0:동, 1:서, 2:남, 3:북
int board[50][50];
bool visit[50][50];
int dp[50][50]; //(x,y)에서 최대 움직일 수 있는 횟수
int n, m, answer;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int solve(int x, int y) {
	if (!inRange(x, y) || board[x][y] == 0) return 0;
	if (visit[x][y] == true) {
		cout << "-1\n";
		exit(0);
	}
	if (dp[x][y] != -1) return dp[x][y];

	visit[x][y] = true;
	dp[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + (board[x][y] * dx[i]);
		int ny = y + (board[x][y] * dy[i]);
		dp[x][y] = max(dp[x][y], solve(nx, ny) + 1);
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
			if (x != 'H') board[i][j] = x - '0';
		}
	}
	memset(dp, -1, sizeof(dp));
	cout<<solve(0,0)<<'\n';
	return 0;
}