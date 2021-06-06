/*
 * DP
 * 11060 점프 점프
 */

#include <iostream>
#include <algorithm>
#define MAX 1001
#define INF 0x3f3f3f
using namespace std;

int a[MAX];
int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill_n(dp, MAX, INF);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= i + a[i] && j <= n; j++) {
			dp[j] = min(dp[j], dp[i] + 1);
		}
	}

	if (dp[n] == INF)
		cout << -1;
	else
		cout << dp[n];

	return 0;
}