using namespace std;

#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>

int main() {
	vector<long long> v;
	int n, x, answer=0;
	cin >> n;
	v.resize(n, 0);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		long long res = v[i], sum;
		int l = 0, r = n - 1;
		while (l < r) {
			sum = v[l] + v[r];
			if (sum == res) {
				if (l != i && r != i) {
					answer++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (sum < res) l++;
			else r--;
		}
	}
	cout << answer << '\n';
	return 0;
}