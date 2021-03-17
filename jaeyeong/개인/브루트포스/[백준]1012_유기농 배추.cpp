using namespace std;
#include <iostream>
#include <cstring>

int board[50][50];
int direction[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n, m, k;

void dfs(int x, int y) {
	board[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (0 <= nx && nx < n && 0 <= ny && ny < m) {
			if(board[nx][ny]==1)
				dfs(nx, ny);
		}
	}
}
int main() {
	int t, cnt;
	int x, y;
	cin >> t;
	for (int test = 0; test < t; test++) {
		cin >> n >> m >> k;
		cnt = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			board[x][y] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 1) {
					dfs(i,j);
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}