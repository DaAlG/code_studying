using namespace std;
#include <iostream>
#include <cstring>

int n;
int board[21][21], cboard[21][21], visit[21][21];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 0;
int answer = -1;
int selected[5];

pair<int, int> getPosition(int x, int y, int num) {
	int dx = direction[num][0];
	int dy = direction[num][1];
	int ox = x, oy = y;
	while (1) {
		if ((x + dx) < 1 || (x + dx) > n || (y + dy) < 1 || (y + dy) > n) break;

		if (board[x + dx][y + dy] != 0){
			if (visit[x + dx][y + dy] == 1) break;
			if (board[ox][oy] == board[x + dx][y + dy]) {
				x += dx;
				y += dy;
			}
			break;
		}
		x += dx;
		y += dy;
	}

	return make_pair(x, y);
}
void move(int dir) {
	pair<int, int> pos;
	if (dir == 2) {
		for (int j = n-1; j >= 1; j--) {
			for (int k = 1; k <= n; k++) {
				pos = getPosition(j, k, dir);
				int nx = pos.first;
				int ny = pos.second;
				if (nx == j && ny == k) continue;
				if (board[nx][ny] == board[j][k] || board[nx][ny] == 0) {
					if (board[nx][ny] != 0)
						visit[nx][ny] = 1;
					board[nx][ny] = board[j][k] + board[nx][ny];
					board[j][k] = 0;
				}

			}
		}
	}
	else if (dir == 0) {
		for (int j = n; j >= 1; j--) {
			for (int k = n-1; k >= 1; k--) {
				pos = getPosition(j, k, dir);
				int nx = pos.first;
				int ny = pos.second;
				if (nx == j && ny == k) continue;
				if (board[nx][ny] == board[j][k] || board[nx][ny] == 0) {
					if (board[nx][ny] != 0)
						visit[nx][ny] = 1;
					board[nx][ny] = board[j][k] + board[nx][ny];
					board[j][k] = 0;
				}
			}
		}
	}
	else if (dir == 1) {
		for (int j = 1; j <= n; j++) {
			for (int k = 2; k <= n; k++) {
				pos = getPosition(j, k, dir);
				int nx = pos.first;
				int ny = pos.second;
				if (nx == j && ny == k) continue;
				if (board[nx][ny] == board[j][k] || board[nx][ny] == 0) {
					if (board[nx][ny] != 0)
						visit[nx][ny] = 1;
					board[nx][ny] = board[j][k] + board[nx][ny];
					board[j][k] = 0;
				}

			}
		}
	}
	else if (dir == 3) {
		for (int j = 2; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				pos = getPosition(j, k, dir);
				int nx = pos.first;
				int ny = pos.second;
				if (nx == j && ny == k) continue;
				if (board[nx][ny] == board[j][k] || board[nx][ny] == 0) {
					if (board[nx][ny] != 0)
						visit[nx][ny] = 1;
					board[nx][ny] = board[j][k] + board[nx][ny];
					board[j][k] = 0;
				}
			}
		}
	}

}


int findMax() {
	int a = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a < board[i][j]) a = board[i][j];
		}
	}
	return a;
}

void copyBoard(int a[][21], int b[][21]) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			b[i][j] = a[i][j];
		}
	}
	return;
}



void solve(int cnt) {
	if (cnt == 5) {
		for (int i = 0; i < 5; i++) {
			move(selected[i]);
			memset(visit, 0, sizeof(visit));
 			for (int i = 1; i <= n; i++) {
				memset(visit[i], 0, sizeof(visit[i]));
			}
		}
		//maxvalue
		int temp = findMax();
		answer = temp > answer ? temp : answer;
		copyBoard(cboard, board);
		return;
	}

	for (int i = 0; i < 4; i++) {
		selected[cnt] = i;
		solve(cnt+1);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0) cnt++;
		}
	}
	copyBoard(board, cboard);
	solve(0);
	cout << answer << '\n';
}