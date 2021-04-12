/*
 * DP
 * 1309 동물원
 */

#include <iostream>
#define MAX 100001
using namespace std;

int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	const int MOD = 9901;

	dp[0] = 1;
	dp[1] = 3;
	dp[2] = 7;

	for (int i = 3; i <= n; i++) {
		// 마지막 줄에 사자 배치 -> dp[i - 1] + dp[i - 2] * 2
		// 마지막 줄에 사자 배치 X -> dp[i - 2] + dp[i - 3]
		dp[i] = dp[i - 1] + dp[i - 2] * 3 + dp[i - 3];
		dp[i] %= MOD;
	}
	cout << dp[n];
	return 0;
}