using namespace std;
#include <iostream>

int dp[41][2];

int main() {
	int tc, n;
    cin >> tc;
	dp[0][0] = 1;
	dp[1][1] = 1;
	for (int i = 2; i <= 40; i++) {
		dp[i][0] = dp[i - 2][0] + dp[i - 1][0];
		dp[i][1] = dp[i - 2][1] + dp[i - 1][1];
	}
	for (int i = 0; i < tc; i++) {
		cin >> n;
		cout << dp[n][0] << ' ' << dp[n][1] << '\n';
	}
	return 0;
}