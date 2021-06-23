/*
 * DP
 * 2096 내려가기
 */

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int a[MAX][3];
int dp[2][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> a[i][j];
		}
	}

	// 최댓값
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		dp[1][0] = max(dp[0][0], dp[0][1]) + a[i][0];
		dp[1][1] = max(dp[0][0], max(dp[0][1], dp[0][2])) + a[i][1];
		dp[1][2] = max(dp[0][1], dp[0][2]) + a[i][2];

		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];
	}
	cout << max(dp[0][0], max(dp[0][1], dp[0][2])) << ' ';
	
	// 최솟값
	dp[0][0] = a[0][0];
	dp[0][1] = a[0][1];
	dp[0][2] = a[0][2];

	for (int i = 1; i < n; i++) {
		dp[1][0] = min(dp[0][0], dp[0][1]) + a[i][0];
		dp[1][1] = min(dp[0][0], min(dp[0][1], dp[0][2])) + a[i][1];
		dp[1][2] = min(dp[0][1], dp[0][2]) + a[i][2];

		dp[0][0] = dp[1][0];
		dp[0][1] = dp[1][1];
		dp[0][2] = dp[1][2];;
	}
	cout << min(dp[0][0], min(dp[0][1], dp[0][2]));
	return 0;
}