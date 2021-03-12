/* 브루트포스
 * 1644 소수의 연속합
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 4000001
using namespace std;

bool prime[MAX];


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill_n(prime, n + 1, 1);
	prime[0] = prime[1] = false;

	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= n; j += i)
				prime[j] = false;
		}
	}

	vector<int> primes;
	for (int i = 2; i <= n; i++) {
		if (prime[i]) {
			primes.push_back(i);
		}
	}

	int answer = 0;
	int size = primes.size();
	int left = 0, right = 0;
	int sum = 0;

	// 투 포인터 알고리즘 O(1)
	while (right <= size && left <= right) {
		if (sum >= n) {
			if (sum == n)
				answer++;

			sum -= primes[left++];
		}
		else {
			if (right == size)
				break;

			sum += primes[right++];
		}
	}
	cout << answer;

	return 0;
}