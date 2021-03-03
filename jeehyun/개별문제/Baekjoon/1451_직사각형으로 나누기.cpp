/* 브루트포스
 * 1451 직사각형으로 나누기
 */

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int rec[101][101];
long long s[101][101];

long long getSum(int x, int y, int nx, int ny)
{
	return s[nx][ny] - s[nx][y - 1] - s[x - 1][ny] + s[x - 1][y - 1];
}

int main()
{
	/*ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);*/

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			scanf("%1d", &rec[i][j]);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (long long)rec[i][j];
		}
	}

	long long ans = 0;
	
	// 세로로 3개
	for (int i = 1; i <= m - 2; i++) {
		for (int j = i + 1; j <= m - 1; j++) {
			long long r1 = getSum(1, 1, n, i);
			long long r2 = getSum(1, i + 1, n, j);
			long long r3 = getSum(1, j + 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}
		}
	}

	// 가로로 3개
	for (int i = 1; i <= n - 2; i++) {
		for (int j = i + 1; j <= n - 1; j++) {
			long long r1 = getSum(1, 1, i, m);
			long long r2 = getSum(i + 1, 1, j, m);
			long long r3 = getSum(j + 1, 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}
		}
	}

	
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m - 1; j++) {
			// 세로로 긴 직사각형이 왼쪽
			long long r1 = getSum(1, 1, n, j);
			long long r2 = getSum(1, j + 1, i, m);
			long long r3 = getSum(i + 1, j + 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}
			
			// 세로로 긴 직사각형이 오른쪽
			r1 = getSum(1, 1, i, j);
			r2 = getSum(i + 1, 1, n, j);
			r3 = getSum(1, j + 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}

			// 가로로 긴 직사각형이 위쪽
			r1 = getSum(1, 1, i, m);
			r2 = getSum(i + 1, 1, n, j);
			r3 = getSum(i + 1, j + 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}
		
			// 가로로 긴 직사각형이 아래쪽
			r1 = getSum(1, 1, i, j);
			r2 = getSum(1, j + 1, i, m);
			r3 = getSum(i + 1, 1, n, m);

			if (ans < r1 * r2 * r3) {
				ans = r1 * r2 * r3;
			}
		}
	}

	cout << ans;
	return 0;
}