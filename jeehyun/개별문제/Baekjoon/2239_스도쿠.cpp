/*
 * 백트래킹
 * 2239 스도쿠
 */

#include <iostream>
using namespace std;

int n = 9;
char board[10][10];
bool c[10][10]; // 세로
bool c2[10][10]; // 가로
bool c3[10][10]; // 3 x 3 정사각형

int square(int x, int y)
{
	return (x / 3) * 3 + (y / 3);
}

bool go(int z)
{
	if (z >= n * n) {
		for (int i = 0; i < n; i++) {
			cout << board[i] << '\n';
		}
		return true;
	}

	int x = z / n;
	int y = z % n;

	if (board[x][y] == '0') {
		for (int i = 1; i <= n; i++) {
			if (!c[x][i] && !c2[y][i] && !c3[square(x, y)][i]) {
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
				board[x][y] = i + '0';
				
				if (go(z + 1))
					return true;

				board[x][y] = '0';
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
			}
		}
	}
	else {
		return go(z + 1);
	}
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < n; i++) {
		cin >> board[i];
		for (int j = 0; j < n; j++) {
			if (board[i][j] != '0') {
				int num = board[i][j] - '0';
				c[i][num] = true;
				c2[j][num] = true;
				c3[square(i, j)][num] = true;
			}
		}
	}

	go(0);
	return 0;
}