/*
 * 수학
 * 17087 숨바꼭질 6
 */

#include <iostream>
#define MAX 100001
using namespace std;

int a[MAX];

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

	int n, s;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = abs(a[i] - s);
	}

	int d = gcd(a[0], a[1]);

	for (int i = 2; i < n; i++) {
		d = min(d, gcd(d, a[i]));
	}
	cout << d;

	return 0;
}