/*
 * DP
 * 12026 BOJ 거리
 */

#include <iostream>
#include <map>
#include <algorithm>
#define MAX 1001
#define INF 0x3f3f3f
using namespace std;

int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string block;
	cin >> block;

	fill(dp, dp + n, INF);
	
	map<char, char> P;
	P['B'] = 'J';
	P['O'] = 'B';
	P['J'] = 'O';

	dp[0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (block[j] == P[block[i]]) {
				dp[i] = min(dp[i], dp[j] + (i - j) * (i - j));
			}
		}
	}

	if (dp[n-1] == INF)
		cout << -1;
	else
		cout << dp[n-1];

	return 0;
}