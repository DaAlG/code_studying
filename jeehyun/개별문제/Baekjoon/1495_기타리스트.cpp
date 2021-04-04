/*
 * DP
 * 1495 기타리스트
 */

#include <iostream>
#define MAX 101
using namespace std;

int arr[MAX];
bool dp[MAX][1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, s, m;
	cin >> n >> s >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[0][s] = true;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (dp[i - 1][j]) {
				if (j + arr[i] <= m)
					dp[i][j + arr[i]] = true;

				if (j - arr[i] >= 0)
					dp[i][j - arr[i]] = true;
			}
		}
	}

	int answer = -1;
	for (int i = 0; i <= m; i++) {
		if (dp[n][i])
			answer = i;
	}

	cout << answer;
	return 0;
}