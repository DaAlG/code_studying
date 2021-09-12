/*
 * DP
 * 2839 설탕 배달
 */

#include <iostream>
#include <algorithm>
#define MAX 5001
#define INF 987654321
using namespace std;

int dp[MAX];

int main()
{
	int n;
	cin >> n;

	fill_n(dp, MAX, INF);
	dp[0] = 0;
	for (int i = 3; i <= n; i++) {
		if (i >= 3) dp[i] = min(dp[i], dp[i - 3] + 1);
		if (i >= 5) dp[i] = min(dp[i], dp[i - 5] + 1);
	}

	if (dp[n] == INF) cout << -1;
	else cout << dp[n];

	return 0;
}