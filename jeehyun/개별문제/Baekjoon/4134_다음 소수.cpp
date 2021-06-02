/*
 * 수학
 * 4134 다음 소수
 */

#include <iostream>
#include <cmath>
#define MAX 4100000000
using namespace std;

bool prime(unsigned int k) {
	if (k < 2) return false;
	
	unsigned int tmp = (unsigned int)sqrt(k);
	for (unsigned int i = 2; i <= tmp; i++) {
		if (k % i == 0)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		unsigned int n;
		cin >> n;

		for (unsigned int i = n; i < MAX; i++) {
			if (prime(i)) {
				cout << i << '\n';
				break;
			}
		}
	}

	return 0;
}