/*
 * 분할정복
 * 11401 이항 계수 3
 */

#include <iostream>
#define MAX 4000001
#define MODULER 1000000007
using namespace std;

long long a, b;

// 분할정복
long long solve(int n)
{
	if (n == 0) return 1;

	if (n % 2) {
		return b * solve(n - 1) % MODULER;
	}
	else {
		long long half = solve(n / 2);
		return half * half % MODULER;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	a = 1;
	// n * (n - 1) * ... (n - k + 1)
	for (int i = n; i >= n - k + 1; i--)
		a = (a * i) % MODULER;

	b = 1;
	// k!
	for (int i = 1; i <= k; i++)
		b = (b * i) % MODULER;

	// k!^(mod-2)
	b = solve(MODULER - 2);

	cout << a * b % MODULER;

	return 0;
}