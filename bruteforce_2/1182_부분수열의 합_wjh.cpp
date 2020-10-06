#include <iostream>
 
using namespace std;

int a[20];
int n, m;
int ans = 0;

void go(int i, int sum) {
	if (i == n) {
		if (sum == m) {
			ans += 1;
		}
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);

	if (m == 0) ans -= 1; // 아무것도 없는 부분수열도 존재 (크기 0)

	cout << ans << endl;
	return 0;
}