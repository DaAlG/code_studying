using namespace std;
#include <iostream>

long long fib[91];

int main() {
	int n;
	cin >> n;
	fib[1] = 1;
	for (int i = 2; i <= n; i++)
		fib[i] = fib[i - 2] + fib[i - 1];
	cout << fib[n] << '\n';
	return 0;
}