/*
 * 수학
 * 4948 베르트랑 공준
 */

#include <iostream>
#include <algorithm>
#define MAX 250000
using namespace std;

bool prime[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	fill_n(prime, MAX, true);
	prime[0] = prime[1] = false;

	for (int i = 2; i < MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}

	int n;
	while (cin >> n) {
		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (prime[i])
				cnt++;
		}
		cout << cnt << '\n';
	}

	return 0;
}