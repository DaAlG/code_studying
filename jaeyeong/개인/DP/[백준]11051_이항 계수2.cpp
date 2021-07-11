using namespace std;
#include <iostream>
#include <cstring>

int dp[1001][1001];

int solve(int n, int k) {
	if (n == k || k == 0) return dp[n][k] = 1;
	if (n < k) return 0;
	if (n < 0 || 1000 < n || k < 0 || 1000 < k) return 0;
	if (dp[n][k] != -1) return dp[n][k];

	return dp[n][k] = (solve(n - 1, k - 1) + solve(n - 1, k)) % 10007;
}

int main() {
	int n, k;
	cin >> n >> k;
	memset(dp, -1, sizeof(dp));
	solve(n, k);
	cout << dp[n][k] << '\n';
	return 0;
}