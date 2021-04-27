/*
 * 수학
 * 2581 소수
 */

#include <iostream>
#include <algorithm>
#define MAX 10001
using namespace std;

bool prime[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	cin >> m >> n;

	fill_n(prime, MAX, 1);
	prime[0] = prime[1] = false;

	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}

	int sum = 0;
	int min = MAX;
	for (int i = m; i <= n; i++) {
		if (prime[i]) {
			sum += i;
			if (min > i) {
				min = i;
			}
		}
	}

	if (sum != 0) {
		cout << sum << '\n';
		cout << min << '\n';
	}
	else {
		cout << -1;
	}

	return 0;
}