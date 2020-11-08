#include <iostream>
#include <vector>

using namespace std;

int go(vector<int> &a) {
	int n = a.size();
	
	// 에너지를 모을 수 있는 게 없음
	if (n == 2) return 0;
	
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + 1);
		energy += go(b);

		if (ans < energy) {
			ans = energy;
		}
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	cout << go(a) << endl;
	return 0;
}