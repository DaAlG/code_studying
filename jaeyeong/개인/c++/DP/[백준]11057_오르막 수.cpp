using namespace std;
#include <iostream>

int dp[1001][10];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += (dp[i - 1][k] % 10007);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 10; i++)
		ans += dp[n][i];
	//답은 10Cn + 중복
	cout << ans % 10007 << '\n';
}