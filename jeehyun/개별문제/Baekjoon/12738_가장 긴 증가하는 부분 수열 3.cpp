/*
 * DP
 * 12738 가장 긴 증가하는 부분 수열 3
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;

	vector<int> vt;
	vt.push_back(-INF);

	int answer = 0;
	for (int i = 0; i < n; i++) {
		cin >> k;
		if (vt.back() < k) {
			vt.push_back(k);
			answer++;
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(), k);
			*it = k;
		}
	}
	cout << answer;

	return 0;
}