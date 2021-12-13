using namespace std;
#include <iostream>
#include <cstring>

int main() {
	int ans;
	int dp[100001] = { 0 };
	int input[100001] = { 0 };

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> input[i];

	dp[1] = input[1];
	ans = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + input[i], input[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans << '\n';

}