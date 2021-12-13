using namespace std;
#include <iostream>
#include <cstring>

char board[9][8][8], temp[8][8];
bool visit[8][8];
int flag = 0;
int dir[9][2] = { {0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1},{0,0} };
// . ºóÄ­, # º®

bool inRange(int x, int y) {
	return 0 <= x && x < 8 && 0 <= y && y < 8;
}
void moveWall(int k) {
	for (int i = 7; 0 < i; i--) {
		for (int j = 0; j < 8; j++) {
			board[k][i][j] = board[k-1][i - 1][j];
		}
	}
	for (int i = 0; i < 8; i++)
		board[k][0][i] = '.';
}
void solve(int sx, int sy, int t) {
	if (flag == 1) return;
	if (t<8 && board[t][sx][sy] == '#') {
		return;
	}
	if ((sx == 0 && sy == 7) || t>=8) {
		flag = 1;
		return;
	}
	for (int i = 0; i < 9; i++) {
		int nx = sx + dir[i][0];
		int ny = sy + dir[i][1];
		if (inRange(nx, ny) && board[t][nx][ny] == '.' && !visit[nx][ny]) {
			visit[nx][ny] = true;
			solve(nx, ny, t + 1);
			visit[nx][ny] = false;
		}
	}
}
int main() {
	char x;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> x;
			board[0][i][j] = x;
		}
	}
	for (int i = 1; i < 8; i++)
		moveWall(i);
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			board[8][i][j] = '.';
		
	visit[0][0] = true;

	solve(7, 0, 0);
	if (flag == 1) cout << "1\n";
	else cout << "0\n";
}