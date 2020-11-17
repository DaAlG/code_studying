#include <iostream>

using namespace std;

int a[10][10];
bool c[10][10];		// i행에 숫자 j가 있으면 true
bool c2[10][10];	// i열에 숫자 j가 있으면 true
bool c3[10][10];	// i번 작은 정사각형에 숫자 j가 있으면 true
int n = 9;

int square(int x, int y) {
	return (x / 3) * 3 + (y / 3);
}

// z번째 칸을 채우는 함수
// 9*x + y번째 칸
bool go(int z) {
	if (z == 81) {
		// 정답이니까 출력
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << endl;
		}
		return true;
	}

	// 행, 열 계산
	int x = z / n;
	int y = z % n;

	if (a[x][y] != 0) {
		// 수가 있으면 채울 필요 없으니까 다음 함수 호출
		return go(z + 1);
	}
	else {
		for (int i = 1; i <= 9; i++) {
			// 행				열				그 행이 포함되는 정사각형 검사
			if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x, y)][i] == 0) {
				// 채우고
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = true;
				a[x][y] = i;

				// 다음 칸 호출
				if (go(z + 1)) {
					return true;
				}

				// 원래대로 돌려주기
				a[x][y] = 0;
				c[x][i] = c2[y][i] = c3[square(x, y)][i] = false;
			}
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];

			if (a[i][j] != 0) { 
				// 빈칸이 아니면 미리 준비
				c[i][a[i][j]] = true;
				c2[j][a[i][j]] = true;
				c3[square(i, j)][a[i][j]] = true;
			}
		}
	}

	// 0번째 칸부터 채우기 시작
	go(0);

	return 0;
}