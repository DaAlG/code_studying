/*
 * DP
 * 15989 1, 2, 3 더하기 4
 */

#include <iostream>
#include <cstring>
#define MAX 10001
using namespace std;

// 정수 i를 만들 때 마지막으로 더한 수가 j인 경우의 수
long long dp[MAX][4];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	dp[0][1] = dp[1][1] = 1;
	dp[2][1] = dp[2][2] = 1;

	for (int i = 3; i < MAX; i++) {
		// 마지막에 더한 수가 1인 경우 
		dp[i][1] = dp[i - 1][1];
		// 마지막에 더한 수가 2인 경우
		dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
		// 마지막에 더한 수가 3인 경우
		dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
	}

	for (int t = 0; t < T; t++) {
		cin >> n;
		cout << dp[n][1] + dp[n][2] + dp[n][3] << '\n';
	}

	return 0;
}