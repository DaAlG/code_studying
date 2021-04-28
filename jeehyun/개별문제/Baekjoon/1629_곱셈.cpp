/*
 * 수학
 * 1629 곱셈
 */

#include <iostream>
using namespace std;

// 분할정복
long long power(long long a, long long b, long long c)
{
	if (b == 1)
		return a;

	long long tmp = power(a, b / 2, c);
	if (b % 2) { // 홀수
		return ((tmp * tmp) % c * a) % c;
	}
	else { // 짝수
		long long tmp = power(a, b / 2, c);
		return (tmp * tmp) % c;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	cout << power(a % c, b, c);

	return 0;
}