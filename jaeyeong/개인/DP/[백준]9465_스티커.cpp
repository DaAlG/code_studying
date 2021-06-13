using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100002

int board[2][MAX], dp[2][MAX];
int n;
int bottomUp(int x, int y) {
	if (y >= n) return 0;
	int& ret = dp[x][y];
	if (dp[x][y] != -1) return ret;
	if (y == n-1) return board[x][y];
	int nx;
	if (x == 0) nx = 1;
	else nx = 0;
	return ret = board[x][y] + max(bottomUp(nx, y + 1), bottomUp(nx, y + 2));
}
int main() {
	int tc;
	cin >> tc;
	
	while (tc--) {
		cin >> n;
		/*bottomUp
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				cin >> board[i][j];
		
		for (int i = 0; i < 2; i++)
			memset(dp[i], -1, sizeof(dp[i]));
		int ans1 = bottomUp(0,0);
		int ans2 = bottomUp(1, 0);
		int ans = max(ans1,ans2);
		*/
		//topDown
		for (int i = 0; i < 2; i++) {
			for (int j = 2; j < n+2; j++) {
				cin >> board[i][j];
				dp[i][j] = board[i][j];
			}
		}
		for (int j = 2; j < n + 2; j++) {
			for (int i = 0; i < 2; i++) {
				if (i == 0) dp[i][j] += max(dp[i + 1][j - 1], dp[i + 1][j - 2]);
				else dp[i][j] += max(dp[i - 1][j - 1], dp[i - 1][j - 2]);
			}
		}
		int ans = max(dp[0][n + 1], dp[1][n + 1]);
		cout << ans << '\n';
	}
}