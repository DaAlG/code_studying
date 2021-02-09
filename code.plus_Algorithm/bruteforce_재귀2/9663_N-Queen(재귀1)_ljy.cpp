/*
!!!!!!!!재귀-백트래킹!!!!!!!
<N-Queen>
N*N크기의 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제
N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오

(입력)
첫째 줄에 N이 주어진다 (1 ≤ N < 15)

(출력)
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력
*/

#include <iostream>

using namespace std;

bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

//위, 아래, 대각선방향에 퀸이 없으면 return true
bool check(int row, int col) {
	//해당 행(column)에 있는가
	if (check_col[col]) {
		return false;
	}
	// (/)방향 대각선에 퀸이 있으면 true
	if (check_dig[row+col]) {
		return false;
	}
	// ↘방향 대각선에 퀸이 있으면 true
	if (check_dig2[row-col+n]) {
		return false;
	}
	return true;
}

//calc(row): row 행에 퀸을 어디에 놓을지 결정하는 function
int calc(int row) {
	if (row == n) {
		//ans += 1;
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			//check리스트, board 처리
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;
			a[row][col] = true;
			//다음 열(row)에 퀸을 놓자
			cnt += calc(row + 1);
			//복구
			check_dig[row + col] = false;
			check_dig2[row - col + n] = false;
			check_col[col] = false;
			a[row][col] = false;
		}
	}
	return cnt;
}
int main() {
	cin >> n;
	cout << calc(0) << '\n';
	return 0;
}