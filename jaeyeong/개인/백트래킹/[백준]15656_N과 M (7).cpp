using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
vector<int> v;
int arr[8];
void comb(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[cnt] = v[i];
		comb(cnt + 1);
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
	comb(0);
	return 0;
}