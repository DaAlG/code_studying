using namespace std;
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

int board[9][9];
int cnt=1;
bool done;
bool visit[10][10]; //쓰인 타일 체크

bool check(int x, int y, int num) {
	for (int i = 0; i < 9; i++) {
		if (board[x][i] == num) return false;
		if (board[i][y] == num) return false;
	}
	int sx = (x / 3) * 3, sy = (y / 3) * 3;
	for (int i = sx; i < sx + 3; i++) {
		for (int j = sy; j < sy + 3; j++) {
			if (board[i][j] == num) return false;
		}
	}
	return true;
}
void solve(int idx) {
	if (done == true) return;
	if (idx == 81) {
		done = true;
		cout << "Puzzle " << cnt << '\n';
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j];
			}
			cout << '\n';
		}
		return;
	}
	int x = idx / 9;
	int y = idx % 9;
	if (board[x][y] != 0)
		solve(idx+1);
	else {
		//가로
		if (y < 8 && board[x][y+1]==0){
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (!visit[i][j]) {
						visit[i][j] = true;
						visit[j][i] = true;
						if (check(x, y, i) && check(x, y + 1, j)) {
							board[x][y] = i;
							board[x][y + 1] = j;
							solve(idx + 2);
							board[x][y] = 0;
							board[x][y + 1] = 0;
						}
						if (check(x, y+1, i) && check(x, y, j)) {
							board[x][y+1] = i;
							board[x][y] = j;
							solve(idx + 2);
							board[x][y+1] = 0;
							board[x][y] = 0;
						}
						visit[i][j] = false;
						visit[j][i] = false;
					}
				}
			}
		}
		//세로
		if (x < 8 && board[x+1][y] == 0) {
			for (int i = 1; i <= 9; i++) {
				for (int j = i + 1; j <= 9; j++) {
					if (!visit[i][j]) {
						visit[i][j] = true;
						visit[j][i] = true;
						if (check(x, y, i) && check(x+1, y, j)) {
							board[x][y] = i;
							board[x+1][y] = j;
							solve(idx + 1);
							board[x][y] = 0;
							board[x+1][y] = 0;
						}
						if (check(x+1, y, i) && check(x, y, j)) {
							board[x+1][y] = i;
							board[x][y] = j;
							solve(idx + 1);
							board[x+1][y] = 0;
							board[x][y] = 0;
						}
						visit[i][j] = false;
						visit[j][i] = false;
					}
				}
			}
		}
	}
}
int main() {
	int n;
	int u, v; //u,v : 도미노에 있는 크기 2인 타일의 각 숫자
	string lu, lv; //lu, lv 각 위치

	cin >> n;
	while (n != 0) {
		for (int i = 0; i < n; i++) {
			cin >> u >> lu >> v >> lv;
			int ux, uy, vx, vy;
			ux = lu[0] - 'A';
			uy = lu[1] - '0' - 1;
			vx = lv[0] - 'A';
			vy = lv[1] - '0' - 1;
			board[ux][uy] = u;
			board[vx][vy] = v;

			visit[u][v] = 1;
			visit[v][u] = 1;
		}

		for (int i = 1; i <= 9; i++) {
			cin >> lu;
			int ux = lu[0] - 'A';
			int uy = lu[1] - '0' - 1;
			board[ux][uy] = i;
		}
		solve(0);
		for (int i = 0; i < 9; i++)
			memset(board[i], 0, sizeof(board[i]));
		for (int i = 1; i < 10; i++)
			memset(visit[i], 0, sizeof(visit[i]));
		cnt++;
		done = false;
		cin >> n;
	}
}