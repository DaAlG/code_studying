using namespace std;
#include <iostream>

int cnt[10];

int main() {
	long long x;
	cin >> x;
	while (x!=0) {
		cnt[x % 10]++;
		x /= 10;
	}
	for (int i = 9; i >= 0; i--) {
		while (cnt[i] != 0) {
			cout << i;
			cnt[i]--;
		}
	}
	cout << '\n';
}