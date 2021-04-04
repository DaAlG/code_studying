/*
 * DP
 * 2293 동전 1
 */

#include <iostream>
#include <vector>
#define AMAX 101
#define CMAX 100001 
using namespace std;

int arr[AMAX];
int dp[CMAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	
	dp[0] = 0;
	for (int i = 0; i < n; i++) {
		dp[arr[i]]++;
		for (int j = arr[i] + 1; j <= k; j++) {
			dp[j] += dp[j - arr[i]];
		}
	}
	
	cout << dp[k];
	return 0;
}