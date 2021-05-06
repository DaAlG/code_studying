#include <iostream>

using namespace std;

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		if (n < 10) cout << n << '\n';
		else {
			int digit = 0;
			int tmp = n;
			int m = 0;
			while (tmp) {
				digit++;
				tmp /= 10;
				m = m * 10 + 1;
			}

			int total = 9 * (digit - 1) + n / m;
			cout << total << '\n';
		}
	}


	return 0;
}