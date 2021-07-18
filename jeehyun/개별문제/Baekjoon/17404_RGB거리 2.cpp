/*
 * DP
 * 17404 RGB거리 2
 */

#include <iostream>
#include <cstring>
#define MAX 1001
#define INF 0x3f3f3f
using namespace std;

int cost[MAX][3];
int dp[MAX][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	memset(dp, INF, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	} 

	int answer = INF;
	for (int i = 0; i < 3; i++) { // 첫 번째 색 고정
		// 첫 번째 색깔을 칠할 때 비용으로 초기화
		for (int j = 0; j < 3; j++) {
			if (i == j) dp[1][j] = cost[1][j];
			else dp[1][j] = INF;
		}

		for (int j = 2; j <= n; j++) {
			dp[j][0] = cost[j][0] + min(dp[j - 1][1], dp[j - 1][2]);
			dp[j][1] = cost[j][1] + min(dp[j - 1][0], dp[j - 1][2]);
			dp[j][2] = cost[j][2] + min(dp[j - 1][0], dp[j - 1][1]);
		}

		for (int j = 0; j < 3; j++) {
			// 첫 번째 집과 마지막 집의 색이 같지 않을 경우에만 갱신
			if (i != j) answer = min(answer, dp[n][j]);
		}
	}
	cout << answer;

	return 0;
}