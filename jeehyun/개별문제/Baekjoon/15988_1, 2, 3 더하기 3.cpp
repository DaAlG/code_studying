/* 
 * DP
 * 15988 1, 2, 3 더하기 3
 */

#include <iostream>
#include <cstring>
#define MAX 1000001
#define MOD 1000000009
using namespace std;

long long dp[MAX];

long long solve(int n)
{
	dp[0] = dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
	}

	return dp[n] % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;
		memset(dp, 0, sizeof(dp));
		cout << solve(n) << "\n";
	}

	return 0;
}