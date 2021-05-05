/*
 * DP
 * 14003 가장 긴 증가하는 부분 수열 5
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n;

	vector<int> vt;
	vector<pair<int, int>> index;

	for (int i = 0; i < n; i++) {
		cin >> k;
		if (vt.empty() || vt.back() < k) {
			vt.push_back(k);
			index.push_back({vt.size() - 1, k});
		}
		else {
			auto it = lower_bound(vt.begin(), vt.end(), k);
			*it = k;

			int idx = distance(vt.begin(), it);
			index.push_back({ idx, k });
		}
	}

	cout << vt.size() << '\n';

	vector<int> LIS;
	int idx = vt.size() - 1;

	for (int i = n - 1; i >= 0; i--) {
		if (index[i].first == idx) {
			idx--;
			LIS.push_back(index[i].second);
		}
	}
	reverse(LIS.begin(), LIS.end());

	for (int i = 0; i < LIS.size(); i++) {
		cout << LIS[i] << ' ';
	}

	return 0;
}