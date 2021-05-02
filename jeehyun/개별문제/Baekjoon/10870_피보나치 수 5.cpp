/*
 * 수학
 * 10870 피보나치 수 5
 */

#include <iostream>
using namespace std;

int dp[21];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n];

	return 0;
}