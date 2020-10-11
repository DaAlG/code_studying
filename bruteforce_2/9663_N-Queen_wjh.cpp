#include <iostream>

using namespace std;

bool a[15][15];
int n;
bool check_col[15];
bool check_dig[40];
bool check_dig2[40];

bool check(int row, int col) {
	// |
	if (check_col[col]) {
		return false; // 이미 있으면 false
	}
	// 왼쪽 위 대각선
	if (check_dig[row + col]) {
		return false;
	}
	// /
	if (check_dig2[row - col + n]) {
		return false;
	}
	return true;
}

int calc(int row) {
	if (row == n) {
		//ans += 1;
		return 1;
	}
	int cnt = 0;
	for (int col = 0; col < n; col++) {
		if (check(row, col)) {
			// '퀸을 놓았다'라고 다른 함수를 위해 미리 처리
			check_dig[row + col] = true;
			check_dig2[row - col + n] = true;
			check_col[col] = true;

			// 실제로 퀸을 놓는다
			a[row][col] = true;

			// 퀸을 어디에 놓을지 결정
			cnt += calc(row + 1);

			// 다시 원래대로 바꿔준다
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
	cout << calc(0) << endl;
	return 0;
}