#include <iostream>
#define MAX 101
using namespace std;

long long dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 1; i < MAX; i++) dp[i][0] = dp[0][i] = 1;

	for (int i = 1; i < MAX; i++) {
		for (int j = 1; j < MAX; j++) {
			dp[i][j] = min((long long)1000000000, dp[i - 1][j] + dp[i][j - 1]);
		}
	}

	if (dp[n][m] < k) {
		cout << -1;
		return 0;
	}

	int acnt = n;
	int zcnt = m;
	for (int i = 0; i < n + m; i++) {
		int astart = dp[acnt - 1][zcnt];
		int zstart = dp[acnt][zcnt - 1];

		if (acnt == 0) {
			cout << 'z';
			zcnt--;
			continue;
		}
		else if (zcnt == 0) {
			cout << 'a';
			acnt--;
			continue;
		}

		if (k <= astart) {
			cout << 'a';
			acnt--;
		}
		else {
			k = k - astart;
			cout << 'z';
			zcnt--;
		}
	}
	return 0;
}