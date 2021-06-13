using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100

int board[MAX][MAX], dp[MAX][MAX];
int n;

int solve(int x, int y) {
	if (x >= n || y >= n) return 0;
	if (x == n - 1 && y == n - 1) return 1;
	//메모지에이션
	int& ret = dp[x][y];
	if (ret != -1) return ret;
	return ret = (solve(x + board[x][y], y) || solve(x, y + board[x][y]));
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		for (int i = 0; i < n; i++)
			memset(dp[i], -1, sizeof(dp[i]));
		int ans = solve(0,0);
		if (ans == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}