using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n, m, x;

	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		/* 이분탐색 손수구현
		int left = 0, right = n - 1;
		bool flag = false;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (v[mid] == x) {
				flag = true;
				break;
			}
			else if (v[mid] < x)
				left = mid + 1;
			else  // x<v[mid]
				right = mid - 1;
		}
		*/
		bool flag = binary_search(v.begin(), v.end(), x);
		cout << flag << '\n';
	}

}