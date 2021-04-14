/*
 * DP
 * 15486 퇴사 2
 */

#include <iostream>
#include <algorithm>
#define MAX 1500002
using namespace std;

int n;
int t[MAX];
int p[MAX];
int dp[MAX]; // A일(A일 그 전날)까지의 최대 액수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	int answer = 0;
	for (int i = 1; i <= n + 1; i++) {
		answer = max(answer, dp[i]);

		if (i + t[i] > n + 1)
			continue;

		dp[i + t[i]] = max(answer + p[i], dp[i + t[i]]);
	}

	cout << answer;
	return 0;
}