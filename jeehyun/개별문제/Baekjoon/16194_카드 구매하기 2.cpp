/*
 * DP
 * 16194 카드 구매하기 2
 */

#include <iostream>
#define MAX 1001
using namespace std;

int p[MAX];
int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	dp[1] = p[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = p[i];
		for (int j = 1; j < i; j++) {
			dp[i] = min(dp[i], dp[i - j] + p[j]);
		}
	}

	cout << dp[n];
	return 0;
}