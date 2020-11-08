#include <iostream>

using namespace std;

bool c[20 * 100000 + 10];
int a[20];
int n;

void go(int i, int sum) {
	if (i == n) {
		c[sum] = true;
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0);
	for (int i = 1;; i++) {
		if (c[i] == false) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}