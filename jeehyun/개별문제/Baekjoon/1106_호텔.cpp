/*
 * DP
 * 1106 호텔
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1101
#define INF 0x3f3f3f
using namespace std;

int dp[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int c, n;
	cin >> c >> n;

	fill_n(dp, MAX, INF);

	vector<pair<int, int>> info(n);
	for (int i = 0; i < n; i++) {
		cin >> info[i].second >> info[i].first;
	}
	sort(info.begin(), info.end());

	dp[0] = 0;
	for (auto t : info) {
		for (int i = t.first; i < MAX; i++) {
			dp[i] = min(dp[i], dp[i - t.first] + t.second);
		}
	}

	int answer = INF;
	for (int i = c; i < MAX; i++) {
		if (answer > dp[i])
			answer = dp[i];
	}
	cout << answer;
	return 0;
}