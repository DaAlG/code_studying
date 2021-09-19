#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	while (T--) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a > b) swap(a, b);

		int n = (a - b) * 2;
		if (b > n || c > n) {
			cout << -1 << "\n";
		}
		else {
			int d = c + n / 2;
			while (d > n) d -= n;
			cout << d << "\n";
		}
	}

	return 0;
}