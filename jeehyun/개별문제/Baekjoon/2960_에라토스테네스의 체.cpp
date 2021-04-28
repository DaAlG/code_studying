/*
 * 수학
 * 2960 에라토스테네스의 체
 */

#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

bool prime[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	fill_n(prime, MAX, 1);

	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			for (int j = i; j <= n; j += i) {
				if (!prime[j]) continue;
				cnt++;
				prime[j] = false;
				if (cnt == k) {
					cout << j;
					return 0;
				}
			}
		}
	}

	return 0;
}