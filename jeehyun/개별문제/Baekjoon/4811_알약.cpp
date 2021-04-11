/*
 * DP
 * 4811 알약
 */

#include <iostream>
#include <cstring>
#define MAX 31
using namespace std;

long long dp[MAX][MAX];

long long solve(int one, int half)
{
	if (one == 0)
		return 1;

	long long& ret = dp[one][half];
	if (ret != -1)
		return ret;

	// 반으로 쪼개서 한 조각을 먹고, 다른 조각은 병에 넣는 경우 
	ret = solve(one - 1, half + 1);

	// 반 조각을 꺼내서 먹는 경우
	if (half > 0) {
		ret += solve(one, half - 1);
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	while (1) {
		memset(dp, -1, sizeof(dp));
		cin >> n;
		if (n == 0) break;
		cout << solve(n, 0) << '\n';
	}

	return 0;
}