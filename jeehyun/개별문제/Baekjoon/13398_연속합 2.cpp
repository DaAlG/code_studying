/*
 * DP
 * 13398 연속합 2
 */

#include <iostream>
#include <algorithm>
#define MAX 100001
using namespace std;

int arr[MAX];
int dp[MAX][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	dp[1][0] = dp[1][1] = arr[1];
	int answer = max(dp[1][0], dp[1][1]);
	for (int i = 2; i <= n; i++) {
		// 수열에서 수를 하나 제거하지 않은 연속합
		dp[i][0] = max(dp[i - 1][0] + arr[i], arr[i]);
		// 수열에서 수를 하나 제거한 연속합
		dp[i][1] = max(dp[i - 1][1] + arr[i], dp[i-1][0]);
		answer = max(answer, max(dp[i][0], dp[i][1]));
	}

	cout << answer;
	return 0;
}