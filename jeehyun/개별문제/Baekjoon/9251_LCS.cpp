/*
 * DP
 * 9251 LCS
 */

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 1001
using namespace std;

int dp[MAX][MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	a.insert(a.begin(), '0');
	b.insert(b.begin(), '0');


	for (int i = 1; i < a.size(); i++) {
		for (int j = 1; j < b.size(); j++) {
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << dp[a.size() - 1][b.size() - 1];

	return 0;
}