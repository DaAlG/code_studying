/*
 * 수학
 * 4134 다음 소수
 */

#include <iostream>
#include <algorithm>
#define MAX 10000005
using namespace std;

bool prime[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long a, b;
	cin >> a >> b;

	fill_n(prime, MAX, true);
	prime[0] = prime[1] = false;

	for (int i = 0; i < MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}

	int answer = 0;
	for (long long i = 2; i < MAX; i++) {
		if (prime[i]) {
			long long tmp = i;
	
			// long long 범위를 넘어가지 않게 체크
			while (tmp <= b / i) {
				tmp *= i;
				if (tmp >= a)
					answer++;
			}
		}
	}
	cout << answer;

	return 0;
}