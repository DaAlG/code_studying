using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n, m, k;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	cin >> m;
	sort(a.begin(), a.end());

	while (m--) {
		cin >> k;
		auto left = lower_bound(a.begin(), a.end(), k);
		auto right = upper_bound(a.begin(), a.end(), k);
		cout << right-left << ' ';
	}
	cout << '\n';
	return 0;
}