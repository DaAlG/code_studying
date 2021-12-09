using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <cmath>
//want: k년이 지난 후 살아남은 나무의 수
int n, m, k;
vector<int> board[11][11], dead[11][11];
int nutrition[11][11], robot[11][11];
int direction[8][2] = { {-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1} };

bool inRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}
void spring() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = board[i][j].size();
			if (size == 0) continue;
			if(size>1)
				sort(board[i][j].begin(), board[i][j].end());
			for (int s = 0; s < size; s++) {
				if (nutrition[i][j] < board[i][j][s]) {
					for (int d = size-1; d >= s; d--) {
						dead[i][j].push_back(board[i][j][d]);
						board[i][j].pop_back();
					}
					break;
				}
				else {
					nutrition[i][j] -= board[i][j][s];
					board[i][j][s]++;
				}
			}
		}
	}
}
void summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = dead[i][j].size();
			if (size == 0) continue;
			for (int s = 0; s < size; s++) {
				nutrition[i][j] += floor(dead[i][j][s] / 2);
			}
			dead[i][j].clear();
		}
	}
}
void fall() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = board[i][j].size();
			if (size == 0) continue;
			for (int s = 0; s < size; s++) {
				if (board[i][j][s] % 5 != 0) continue;
				int newtree[8] = { 0 };
				for (int d = 0; d < 8; d++) {
					int nx = i + direction[d][0];
					int ny = j + direction[d][1];
					if (!inRange(nx, ny)) continue;
					newtree[d]++;
				}
				for (int d = 0; d < 8; d++) {
					if (!newtree[d]) continue;
					int nx = i + direction[d][0];
					int ny = j + direction[d][1];
					while (newtree[d]--) {
						board[i + direction[d][0]][j + direction[d][1]].push_back(1);
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			nutrition[i][j] += robot[i][j];
		}
	}
}
int main() {
	cin >> n >> m >> k;
	//input
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> robot[i][j];
			nutrition[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		int x, y, age;
		cin >> x >> y>> age;
		board[x][y].push_back(age);
	}
	//solution
	for (int i = 0; i < k; i++) {
		spring();
		summer();
		fall();
		winter();
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int size = board[i][j].size();
			answer += size;
		}
	}
	cout << answer << '\n';
}