/*
 * DP
 * 11058 크리보드
 */

#include <iostream>
#define MAX 101
using namespace std;

long long dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++) {
		dp[i] = dp[i - 1] + 1;
		// 연속해서 복사하는 경우
		for (int j = 1; j <= i - 3; j++) {
			dp[i] = max(dp[i], dp[i - (j + 2)] * (j + 1));
		}
	}

	cout << dp[n];
	return 0;
}