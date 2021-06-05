/*
 * 수학
 * 17103 골드바흐 파티션
 */

#include <iostream>
#include <algorithm>
#define MAX 1000001
using namespace std;

bool prime[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	fill_n(prime, MAX, true);
	prime[0] = prime[1] = false;
	
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}
	
	while (T--) {
		cin >> n;

		int answer = 0;
		for (int i = 2; i <= n / 2; i++) {
			if (prime[i] && prime[n - i])
				answer++;
		}
		cout << answer << '\n';
	}

	return 0;
}