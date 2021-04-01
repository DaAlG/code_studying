using namespace std;
#include <iostream>
#include <queue>
#define rock -100000

int r, c;
char board[50][50];
int visit[50][50]; //0: empty, -100000: µ¹, -1: ¹°
int direction[4][2] = { {0,1}, {0,-1},{1,0},{-1,0} };

void print() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
	cout << '\n';
}
void bfs(int sx, int sy) {
	queue<pair<int, int>> q;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			if (board[i][j] == '*') q.push(make_pair(i, j));

	visit[sx][sy] = 1;
	q.push(make_pair(sx, sy));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < r && 0 <= ny && ny < c) {
				if (visit[x][y] == -1 && board[x][y] != 'S') {
					if (visit[nx][ny] != -1 && board[nx][ny] != 'D' && board[nx][ny] != 'X') {
						if (board[nx][ny] == 'S')
							visit[nx][ny] *= -1;
						else
							visit[nx][ny] = -1;
						q.push(make_pair(nx, ny));
					}
				}
				else if (board[x][y] == 'S') {
					if (visit[nx][ny] == 0) {
						if(visit[x][y] < 0) visit[nx][ny] = visit[x][y] * (-1) + 1;
						else visit[nx][ny] = visit[x][y] + 1;
							
						if(board[nx][ny]!='D') board[nx][ny] = 'S';
						q.push(make_pair(nx, ny));
					}
					if (i == 3) {
						if(visit[x][y] == -1) board[x][y] = '*';
						else board[x][y] = '.';
					}
				}
				
			}
		}
	}
}
int main() {
	char x;
	int sx, sy, dx, dy;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> x;
			board[i][j] = x;
			if (x == 'S') {
				sx = i;
				sy = j;
			}
			if (x == '*') visit[i][j] = -1;
			if (x == 'X') visit[i][j] = rock;
			if (x == 'D') {
				dx = i;
				dy = j;
			}
		}
	}
	bfs(sx,sy);
	if (visit[dx][dy] == 0) cout << "KAKTUS" << '\n';
	else cout << visit[dx][dy]-1 << '\n';
}