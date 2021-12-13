using namespace std;
#include <iostream>
#include <string.h>
#define n 12
#define m 6

char board[n][m];
bool visit[n][m] = { false };
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int checkDFS(int x, int y, int cnt) {
	int answer = 1;
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (inRange(nx, ny) && !visit[nx][ny] && board[x][y] == board[nx][ny])
			answer += checkDFS(nx, ny, cnt + 1);
	}
	return answer;
}
void bombDFS(int x, int y) {
	char cur = board[x][y];
	board[x][y] = '.';
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (inRange(nx, ny) && cur == board[nx][ny])
			bombDFS(nx, ny);
	}
}
bool canBomb() {
	int tempBoard[n][m] = { 0 };
	bool flag = false;
	for(int i=0;i<n;i++)
		memset(visit[i], false, sizeof(visit[i]));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == '.' || visit[i][j]) continue;
			if (checkDFS(i, j, 1) < 4) continue;
			bombDFS(i, j);
			flag = true;
		}
	}
	return flag;
}
void gravity() {
	for (int j = 0; j < m; j++) {
		int top=-1;
		for (int i = n-1; 0 <= i; i--) {
			if (top == -1 && board[i][j] == '.')
				top = i;
			else if (top != -1 && board[i][j] != '.') {
				board[top][j] = board[i][j];
				board[i][j] = '.';
				top--;
			}
		}
	}
}
int main() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>board[i][j];
		}
	}
	int answer = 0;
	while (canBomb()) {
		gravity();
		answer++;
	}
	cout << answer << '\n';
} 