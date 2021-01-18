// SW Expert Academy
// S/W 문제해결 기본 2일차 - 1211 Ladder2

#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T = 10;
	const int n = 100;
	int a[n + 1][n + 1];
	int min, ans;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}

		min = 99999; ans = 0;
		for (int k = 0; k < n; k++) {
			if (a[0][k] == 0)
				continue;

			int sum = 0;
			for (int r = 0, c = k; r < n; r++, sum++) {
				if (c < n && a[r][c + 1]) {
					for (; c < n && a[r][c + 1]; c++, sum++);
				}
				else if (c && a[r][c - 1]) {
					for (; c && a[r][c - 1]; c--, sum++);
				}
			}

			if (sum < min) {
				min = sum;
				ans = k;
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}