using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

vector<int> v;
int ans[7];

int sum() {
	int k = 0;
	for (int i = 0; i < 7; i++)
		k += ans[i];
	return k;
}
void combination(int cnt, int idx) {
	if (cnt == 7) {
		if (sum() == 100) {
			sort(ans, ans + 7);
			for (int i = 0; i < 7; i++)
				cout << ans[i] << '\n';
			exit(0);
		}
		return;
	}
	if (idx == 9) return;

	for (int i = idx; i < 9; i++) {
		ans[cnt] = v[i];
		combination(cnt + 1, i + 1);
	}
	
}
int main() {
	int x;
	for (int i = 0; i < 9; i++) {
		cin >> x;
		v.push_back(x);
	}
	combination(0, 0);
}