/*
 * DP
 * 14002 가장 긴 증가하는 부분 수열 4
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1010
using namespace std;

vector<int> LIS[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> arr(n);
	vector<int> dp(n);
	vector<int> p(n, -1);
	vector<int> answer;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		p[i] = i;
		LIS[i].push_back(arr[i]);
		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + 1) {
				LIS[i].clear();
				LIS[i] = LIS[j];
				LIS[i].push_back(arr[i]);
				dp[i] = dp[j] + 1;
			}
		}

		if (answer.size() < LIS[i].size())
			answer = LIS[i];
	}

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ' ';
	
	return 0;
}