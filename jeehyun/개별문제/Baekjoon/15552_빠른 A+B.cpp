/*
 * 수학
 * 15552 빠른 A+B
 */

#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, a, b;
	cin >> T;

	while (T--) {
		cin >> a >> b;
		cout << a + b << '\n';
	}

	return 0;
}