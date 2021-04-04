/*
 * 브루트포스
 * 1748 수 이어 쓰기 1
 */

#include <iostream>
using namespace std;

int size(int n)
{
	int s = 0;
	while (n) {
		s++;
		n /= 10;
	}
	return s;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	int n_size = size(n);
	int answer = 0;
	int len = 1;
	int mod = 10;

	while (len <= n_size) {
		if (n / mod)
			answer += len * (mod - mod / 10);
		else if (n % mod)
			answer += len * (n % mod - mod / 10 + 1);

		len++;
		mod *= 10;
	}
	
	cout << answer;
	return 0;
}