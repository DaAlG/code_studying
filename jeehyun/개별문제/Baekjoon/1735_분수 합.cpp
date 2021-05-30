/*
 * 수학
 * 1735 분수 합
 */

#include <iostream>
using namespace std;

// 최대공약수
int gcd(int a, int b)
{
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 분자, 분모
	int a[2], b[2];
	for (int i = 0; i < 2; i++) {
		cin >> a[i] >> b[i];
	}

	long long deno = b[0] * b[1] / gcd(b[0], b[1]); // 분모
	long long numer = (a[0] * deno / b[0]) + (a[1] * deno / b[1]); // 분자

	int tmp = gcd(numer, deno);
	numer /= tmp;
	deno /= tmp;

	cout << numer << ' ' << deno;
	return 0;
}