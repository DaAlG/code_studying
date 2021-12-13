using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int ABS(int a) {
	if (a < 0)
		return a * (-1);
	else
		return a;
}

int cal(vector<int> v, int n) {
	int sum = 0;
	for (int i = 0; i < (n-1); i++) {
		sum += ABS(v[i] - v[i + 1]);
	}
	return sum;
}

int main() {
	int n, ans = -1;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	do {
		int temp = cal(v, n);
		if (temp > ans) ans = temp;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
}