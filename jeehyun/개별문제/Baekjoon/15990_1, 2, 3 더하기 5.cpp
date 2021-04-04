/*
 * DP
 * 15988 1, 2, 3 더하기 3
 */

#include <iostream>
#include <cstring>
#define MAX 1000001
#define MOD 1000000009
using namespace std;

// dp[n][i] = 마지막에 오는 수가 i일 때, 1, 2, 3의 합으로 정수 n을 만드는 경우의 수
long long dp[MAX][4];

void solve()
{
	dp[1][1] = dp[2][2] = 1;
	dp[3][1] = dp[3][2] = dp[3][3] = 1;

	for (int i = 4; i < MAX; i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-1][3]) % MOD;
		dp[i][2] = (dp[i-2][1] + dp[i-2][3]) % MOD;
		dp[i][3] = (dp[i-3][1] + dp[i-3][2]) % MOD;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	solve();
	for (int t = 0; t < T; t++) {
		cin >> n;
		int answer = (dp[n][1] + dp[n][2] + dp[n][3]) % MOD;
		cout << answer << "\n";
	}

	return 0;
}