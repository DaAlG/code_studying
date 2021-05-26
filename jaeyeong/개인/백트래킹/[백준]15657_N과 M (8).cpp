using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

int n, m;
vector<int> v;
set<string> ans;
int arr[9], temp[9];

void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; i++) {
		arr[cnt] = v[i];
		comb(i, cnt + 1);
	}
}
int main() {
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	comb(0, 0);
	return 0;
}