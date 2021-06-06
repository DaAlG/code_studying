/*
 * DP
 * 1932 정수 삼각형
 */

#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int a[MAX][MAX];
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}

	dp[1][1] = a[1][1];
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			// 대각선 왼쪽
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + a[i + 1][j]);
			// 대각선 오른쪽
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + a[i + 1][j + 1]);
		}
	}
	cout << *max_element(dp[n] + 1, dp[n] + n + 1);

	return 0;
}