/*
 * 수학
 * 5347 LCM
 */

#include <iostream>
using namespace std;

unsigned long long gcd(unsigned long long a, unsigned long long b)
{
	while (b != 0) {
		unsigned long long r = a % b;
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

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		unsigned long long a, b;
		cin >> a >> b;
		unsigned long long lcm = a * b / gcd(a, b);
		cout << lcm << '\n';
	}

	return 0;
}