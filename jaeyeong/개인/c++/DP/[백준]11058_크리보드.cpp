// int로 하면 틀렸다. long long으로 하니 맞았다.
using namespace std;
#include <iostream>

int main() {
	int n;
	long long dp[101] = { 0 };
	long long d[101] = { 0 };
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++) {
		long long c = dp[i - 1] + 1;
		for (int j = 1; j <= (i - 3); j++) {
			long long buf = dp[j];
			long long num_buf = i - (j + 2);
			c = max(c, dp[j] + buf * num_buf);
		}
		dp[i] = c;
	}
	cout << dp[n] << '\n';
	return 0;
}