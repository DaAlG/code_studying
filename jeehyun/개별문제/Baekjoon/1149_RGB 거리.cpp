/*
 * DP
 * 1149 RGB 거리
 */

#include <iostream>
#include <cstring>
#include <algorithm>
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

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> cost[i][j];
		}
	}

	memset(dp, INF, sizeof(dp));

	dp[1][0] = cost[1][0];
	dp[1][1] = cost[1][1];
	dp[1][2] = cost[1][2];

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (k == j) continue;
				dp[i][j] = min(dp[i][j], cost[i][j] + dp[i - 1][k]);
			}
		}
	}

	cout << *min_element(dp[n], dp[n] + 3);
	return 0;
}