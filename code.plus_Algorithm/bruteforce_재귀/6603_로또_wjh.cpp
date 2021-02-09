#include <iostream>
#include <vector>

using namespace std;

vector<int> lotto; // 함수가 선택한 수 저장

void solve(vector<int> &a, int index, int cnt) {
	if (cnt == 6) {
		for (int num : lotto) {
			cout << num << " ";
		}
		cout << endl;
		return;
	}
	int n = a.size();

	if (n == index) return;

	// index번째를 선택
	lotto.push_back(a[index]);
	solve(a, index + 1, cnt + 1);

	// index번째를 선택 x
	lotto.pop_back();
	solve(a, index + 1, cnt);
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;

		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		solve(a, 0, 0);
		cout << endl;
	}
	return 0;
}