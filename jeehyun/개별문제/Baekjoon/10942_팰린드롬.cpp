/*
 * DP
 * 10942 팰린드롬?
 */

#include <iostream>
#define MAX 2001
using namespace std;

int a[MAX];
int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	// 자기자신은 항상 팰린드롬
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}

	// 길이가 2일 때 팰린드롬인지 확인
	for (int i = 1; i < n; i++) {
		if (a[i] == a[i + 1])
			dp[i][i + 1] = 1;
	}

	for (int k = 3; k <= n; k++) { // 팰린드롬 길이
		for (int i = 1; i <= n - k + 1; i++) {
			// i  i+1  i+2  ... i+k-3 i+k-2  i+k-1
			// dp[i+1][i+k-2]가 팰린드롬이고 a[i] == a[i+k-1]이면 dp[i][i+k-1]도 팰린드롬
			if (a[i] == a[i + k - 1] && dp[i + 1][i + k - 2])
				dp[i][i + k - 1] = 1;
		}
	}

	cin >> m;
	while (m--) {
		int s, e;
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}

	return 0;
}