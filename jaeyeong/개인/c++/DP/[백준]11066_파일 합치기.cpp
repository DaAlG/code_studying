// http://melonicedlatte.com/algorithm/2018/03/22/051337.html
using namespace std;
#include <iostream>
#include <vector>
#define INF 0x3f3f3f3f

int dp[501][501];
int cost[501], sum[501];

int solution(int x, int y) {
	if (dp[x][y] != INF) {
		return dp[x][y];
	}
	if (x == y) {
		return dp[x][y] = 0;
	}
	if (x + 1 == y) {
		return dp[x][y] = cost[x] + cost[y];
	}
	for (int mid = x; mid < y; mid++) {
		int left = solution(x, mid);
		int right = solution(mid + 1, y);
		dp[x][y] = min(dp[x][y], left + right);
	}

	return dp[x][y] += sum[y] - sum[x - 1];
}
int main() {
	int test, n, k;

	cin >> test;

	for (int t = 0; t < test; t++) {
		memset(dp, INF, sizeof(dp));
		memset(sum, 0, sizeof(sum));
		cin >> n;

		for (int j = 1; j <= n; j++) {
			cin >> cost[j];
			sum[j] += cost[j] + sum[j - 1];
		}

		cout << solution(1, n) << '\n';
	}
}