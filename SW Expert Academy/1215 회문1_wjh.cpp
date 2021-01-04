// SW Expert Academy
// S/W 문제해결 기본 3일차 - 1215 회문1

#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T = 10;
	const int n = 8;

	for (test_case = 1; test_case <= T; ++test_case) {
		int len;
		cin >> len;

		char map[n][n];

		for (int i = 0; i < n; i++) {
			cin >> map[i];
		} 

		int ans = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= n - len; j++) {
				int f, e;
				// 가로
				for (f = j, e = j + len - 1; f < e; f++, e--) {
					if (map[i][f] != map[i][e])
						break;
				}
				if (f >= e)
					ans++;
				// 세로
				for (f = j, e = j + len - 1; f < e; f++, e--) {
					if (map[f][i] != map[e][i])
						break;
				}
				if (f >= e)
					ans++;
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}