/*
 * 백트래킹
 * 2023 신기한 소수
 */

#include <iostream>
#include <cmath>
using namespace std;

int n;

bool prime(int k) {
	if (k < 2) return false;

	int tmp = (int)sqrt(k);
	for (int i = 2; i <= tmp; i++) {
		if (k % i == 0)
			return false;
	}
	return true;
}

void go(int k, int digit)
{
	if (digit == n) {
		cout << k << '\n';
		return;
	}

	for (int i = 1; i < 10; i++) {
		int tmp = k * 10 + i;
		if (prime(tmp)) {
			go(tmp, digit + 1);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	
	go(2, 1);
	go(3, 1);
	go(5, 1);
	go(7, 1);

	return 0;
}