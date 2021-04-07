/*
 * DP
 * 10422 괄호
 */

#include <iostream>
#define MAX 5001
#define MODULER 1000000007
using namespace std;

long long dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	dp[0] = 1;
	dp[2] = 1;

	// 카탈란 수
	for (int i = 4; i < MAX; i += 2) {
		for (int j = 2; j <= i; j += 2) {
			dp[i] += dp[i - j] * dp[j - 2];
			dp[i] %= MODULER;
		}
	}

	for (int t = 0; t < T; t++) {
		cin >> n;
		cout << dp[n] << '\n';
	}
	
	return 0;
}