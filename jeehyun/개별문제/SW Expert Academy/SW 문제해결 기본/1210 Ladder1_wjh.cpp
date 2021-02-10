// SW Expert Academy
// S/W 문제해결 기본 2일차 - 1210 Ladder1

#include <iostream>

using namespace std;

int main() 
{
	int test_case;
	int T = 10;
	const int n = 100;
	int a[n+1][n+1];
	int goal;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];

				if (a[i][j] == 2)
					goal = j;
			}
		}

		int r = n;
		while (r--) {
			if (goal < n && a[r][goal + 1]) {
				while (goal < n && a[r][goal + 1])
					goal++;
			}
			else if (goal && a[r][goal - 1]) {
				while (goal &&  a[r][goal - 1])
					goal--;
			}
		}

		cout << "#" << test_case << " " << goal << endl;
	}

	return 0;
}