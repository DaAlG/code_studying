// SW Expert Academy
// S/W 문제해결 기본 3일차 - 1216 회문2

#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T = 10;
	const int n = 100;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		char map[n][n+1];
		for (int i = 0; i < n; i++) {
			cin >> map[i];
		}

		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - ans; j++) {
				int f, e, len;
				
				// 가로
				for (int k = j + 1; k < n; k++) {
					if (map[i][k] == map[i][j]) {
						len = k - j + 1;
					
						for (f = j, e = j + len - 1; f < e; f++, e--) {
							if (map[i][f] != map[i][e])
								break;
						}
						if (f >= e && len > ans)
							ans = len;
					}
				}
				
				// 세로
				for (int k = j + 1; k < n; k++) {
					if (map[k][i] == map[j][i]) {
						len = k - j + 1;
						for (f = j, e = j + len - 1; f < e; f++, e--) {
							if (map[f][i] != map[e][i])
								break;
						}
						if (f >= e && len > ans)
							ans = len;
					}
				}
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}