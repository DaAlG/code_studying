/*
 * DP
 * 2294 동전 2
 */

#include <iostream>
#include <vector>
#define INF 100001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> arr(n);
	vector<int> dp(k + 1, INF);

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = arr[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - arr[i]] + 1);
		}
	}
	
	if (dp[k] != INF)
		cout << dp[k];
	else
		cout << -1;

	return 0;
}