/*
 * 구현
 * 14890 경사로
 */

#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int n, L;
int map[MAX][MAX];

bool possible(int now, int flag)
{
	vector<bool> slope(n); // 경사로 지었는지 표시

	if (flag) { // 가로
		for (int col = 1; col < n; col++) {
			// 높이 차이가 2 이상이면 경사로를 놓을 수 없다
			if (abs(map[now][col] - map[now][col - 1]) >= 2)
				return false;

			// 오르막길
			if (map[now][col] == map[now][col - 1] + 1) {
				bool impossible = false;

				// 경사로를 놓을 수 있는지 확인
				// 오르막길이기 때문에 col - L부터 col - 1까지 검사
				for (int i = col - 1; i >= col - L; i--) {
					if (i < 0 || i >= n || slope[i] || map[now][i] != map[now][col - 1]) {
						impossible = true;
						break;
					}
				}

				// 길이가 부족하면 경사로 설치 불가능
				if (impossible)
					return false;

				// 경사로 설치 정보 저장
				for (int i = col - 1; i >= col - L; i--) {
					slope[i] = true;
				}
			}
			// 내리막길
			else if (map[now][col] == map[now][col - 1] - 1) {
				bool impossible = false;

				// 경사로를 놓을 수 있는지 확인
				// 내리막길이기 때문에 col부터 col + L - 1까지 검사
				for (int i = col; i < col + L; i++) {
					if (i < 0 || i >= n || slope[i] || map[now][i] != map[now][col]) {
						impossible = true;
						break;
					}
				}

				if (impossible)
					return false;

				for (int i = col; i < col + L; i++) {
					slope[i] = true;
				}
			}
		}
	}
	else { // 세로
		for (int row = 1; row < n; row++) {
			if (abs(map[row][now] - map[row - 1][now]) >= 2)
				return false;

			if (map[row][now] == map[row - 1][now] + 1) {
				bool impossible = false;

				for (int i = row - 1; i >= row - L; i--) {
					if (i < 0 || i >= n || slope[i] || map[i][now] != map[row - 1][now]) {
						impossible = true;
						break;
					}
				}

				if (impossible)
					return false;

				for (int i = row - 1; i >= row - L; i--) {
					slope[i] = true;
				}
			}
			else if (map[row][now] == map[row - 1][now] - 1) {
				bool impossible = false;

				for (int i = row; i < row + L; i++) {
					if (i < 0 || i >= n || slope[i] || map[i][now] != map[row][now]) {
						impossible = true;
						break;
					}
				}

				if (impossible)
					return false;

				for (int i = row; i < row + L; i++) {
					slope[i] = true;
				}
			}
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> L;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	int answer = 0;
	for (int i = 0; i < n; i++) {
		// 가로줄
		if (possible(i, 1))
			answer++;

		// 세로줄
		if (possible(i, 0))
			answer++;
	}
	cout << answer;

	return 0;
}