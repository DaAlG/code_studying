/*
 * 브루트포스
 * 9663 N-Queen
 */

#include <iostream>
using namespace std;

int n;
bool a[15][15];
bool c[15]; // 세로
bool dig1[40]; // 오른쪽 위 대각선
bool dig2[40]; // 윈쪽 위 대각선

bool check(int row, int col)
{
	// 세로 체크
	if (c[col])
		return false;

	// 오른쪽 위 대각선 확인
	if (dig1[row + col])
		return false;

	// 왼쪽 위 대각선 확인
	if (dig2[row - col + n])
		return false;

	return true;
}


int solve(int row)
{
	if (row == n)
		return 1;

	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) { // 퀸을 놓을 수 있는지 체크
			a[row][col] = true;
			c[col] = true;
			dig1[row + col] = true;
			dig2[row - col + n] = true;

			// 퀸을 놓는다
			cnt += solve(row + 1);

			a[row][col] = false;
			c[col] = false;
			dig1[row + col] = false;
			dig2[row - col + n] = false;
		}
	}

	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	cout << solve(0);
	return 0;
}