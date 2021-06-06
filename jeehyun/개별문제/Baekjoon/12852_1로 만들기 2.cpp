/*
 * DP
 * 12852 1로 만들기 2
 */

#include <iostream>
#include <algorithm>
#define MAX 1000001
#define INF 0x7fffffff
using namespace std;

int dp[MAX];
int parent[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill_n(dp, MAX, INF);
	dp[0] = dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		// X에서 1을 뺄 때의 연산 횟수로 초기화
		dp[i] = dp[i - 1] + 1;
		parent[i] = i - 1;

		// X가 2로 나누어 떨어지고 최소 횟수라면 갱신
		if (i % 2 == 0 && dp[i / 2] + 1 < dp[i]) {
			dp[i] = dp[i / 2] + 1;
			parent[i] = i / 2;
		}

		// X가 3로 나누어 떨어지고 최소 횟수라면 갱신
		if (i % 3 == 0 && dp[i / 3] + 1 < dp[i]) {
			dp[i] = dp[i / 3] + 1;
			parent[i] = i / 3;
		}
	}
	cout << dp[n] << '\n';

	cout << n << ' ';
	// parent가 0이 아닐 때(1)까지 수 출력
	for (int p = parent[n]; p != 0; p = parent[p]) {
		cout << p << ' ';
	}
	cout << '\n';

	return 0;
}