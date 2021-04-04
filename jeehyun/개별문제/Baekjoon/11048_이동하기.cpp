/*
 * DP
 * 11048 이동하기
 */

#include <iostream>
#include <vector>
#define MAX 1001 
using namespace std;

int arr[MAX][MAX];
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = arr[i][j];

			if (i - 1 > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + arr[i][j]);

			if (j - 1 > 0)
				dp[i][j] = max(dp[i][j], dp[i][j - 1] + arr[i][j]);

			if (i - 1 > 0 && j - 1 > 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + arr[i][j]);
		}
	}

	cout << dp[n][m];
	return 0;
}