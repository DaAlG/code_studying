/*
 * DP
 * 17212 달나라 토끼를 위한 구매대금 지불 도우미
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

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		dp[i] = min(dp[i], dp[i - 2] + 1);

		if (i - 5 >= 0)
			dp[i] = min(dp[i], dp[i - 5] + 1);

		if (i - 7 >= 0)
			dp[i] = min(dp[i], dp[i - 7] + 1);	
	}
	cout << dp[n];

	return 0;
}