/*
 * 이분탐색
 * 2512 예산
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

	int n, m;
	cin >> n;

	vector<int> budget(n);
	int sum = 0;

	for (int i = 0; i < n; i++) {
		cin >> budget[i];
		sum += budget[i];
	}
	cin >> m;

	sort(budget.begin(), budget.end());

	if (sum > m) {
		int maxi = 0;
		int maxPrice = m / n;
		int mp = maxPrice;

		while (1) {
			int tsum = 0;
			for (int i = 0; i < budget.size(); i++) {
				if (budget[i] <= mp)
					tsum += budget[i];
				else
					tsum += mp;
			}

			if (tsum > m)
				break;

			if (maxi < tsum) {
				maxi = tsum;
				maxPrice = mp;
			}

			mp++;
		}
		cout << maxPrice;
	}
	else {
		cout << *max_element(budget.begin(), budget.end());
	}

	return 0;
}