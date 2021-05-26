/*
 * 수학
 * 1747 소수&팰린드롬
 */

#include <iostream>
#include <string>
#include <algorithm>
#define MAX 10000001
using namespace std;

bool prime[MAX];

bool palindrome(string s)
{
	int n = s.size() - 1;
	for (int i = 0; i < s.size() / 2; i++) {
		if (s[i] != s[n - i])
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	fill_n(prime, MAX, true);

	prime[0] = prime[1] = false;
	for (int i = 2; i < MAX; i++) {
		if (prime[i]) {
			for (int j = i * 2; j < MAX; j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = n; i < MAX; i++) {
		if (prime[i] && palindrome(to_string(i))) {
			cout << i << '\n';
			break;
		}
	}

	return 0;
}