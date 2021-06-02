/*
 * 백트래킹
 * 1799 비숍
 */

#include <iostream>
#define MAX 10
using namespace std;

int n;
int map[11][11];

bool dig1[21]; // 오른쪽 위 대각선
bool dig2[21]; // 왼쪽 위 대각선

bool possible(int row, int col)
{
	// 오른쪽 위 대각선
	if (dig1[row + col])
		return false;

	// 왼쪽 위 대각선
	if (dig2[row - col + n])
		return false;

	return true;
}


int go(int row, int col, int cnt)
{
	if (col >= n) {
		row++;
		// 이번 행에서 짝수 열이었다면 다음 행에서는 홀수 열
		// 이번 행에서 홀수 열이었다면 다음 행에서는 짝수 열
		if (col % 2 == 0) col = 1;
		else col = 0;
	}

	if (row >= n)
		return cnt;


	int ret = 0;

	// 대각선 방향에 비숍이 놓여져 있지 않으면 비숍을 놓을 수 있다
	if (map[row][col] && possible(row, col)) {
			dig1[row + col] = true;
			dig2[row - col + n] = true;

			ret = max(ret, go(row, col + 2, cnt + 1));

			dig1[row + col] = false;
			dig2[row - col + n] = false;
	}
	
	// 비숍을 놓지 않고 넘어가는 경우
	ret = max(ret, go(row, col + 2, cnt));

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int answer = go(0, 0, 0); // 검은색칸
	answer += go(0, 1, 0); // 흰색칸
	cout << answer;

	return 0;
}