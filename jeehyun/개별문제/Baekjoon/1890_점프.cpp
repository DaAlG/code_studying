/*
 * DP
 * 1890 점프
 */

#include <iostream>
#define MAX 101
#define INF 0x3f3f3f
using namespace std;

int board[MAX][MAX];
long long dp[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = {0, 1};
int dy[] = {1, 0};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	dp[1][1] = 1;
	visited[1][1] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!visited[i][j] || (i == n && j == n))
				continue;

			int jump = board[i][j];
			if (j + jump <= n) {
				dp[i][j + jump] += dp[i][j];
				visited[i][j + jump] = true;
			}

			if (i + jump <= n) {
				dp[i + jump][j] += dp[i][j];
				visited[i + jump][j] = true;
			}
		}
	}

	cout << dp[n][n];
	return 0;
}