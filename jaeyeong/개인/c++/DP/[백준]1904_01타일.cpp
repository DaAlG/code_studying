using namespace std;
#include <iostream>
#define MAX 1000001

int dp[MAX];
int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2]) % 15746;
	}
	cout << dp[n] << '\n';
}