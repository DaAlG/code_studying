/*
 * 이분 탐색
 * 1300 K번째 수
 */

#include <iostream>
using namespace std;

long long n, k;

long long count(long long num)
{
	long long cnt = 0;
	for (long long i = 1; i < n + 1; i++) {
		cnt += min(n, num / i);
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	long long left = 1;
	long long right = n * n;
	long long answer = 1;

	while (left <= right) {
		long long mid = (left + right) / 2;

		if (count(mid) < k)
			left = mid + 1;
		else {
			answer = mid;
			right = mid - 1;
		}
	}
	cout << answer;
	return 0;
}