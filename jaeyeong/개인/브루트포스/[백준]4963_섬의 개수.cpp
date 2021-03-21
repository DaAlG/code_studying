using namespace std;
#include <iostream>

int w, h;
int board[50][50];
int direction[8][2] = { {1,0},{-1,0},{0,1},{0,-1},
	{1,1}, {-1,-1}, {-1,1}, {1,-1} };

void dfs(int x, int y) {
	for (int i = 0; i < 8; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (0 <= nx && nx < w && 0 <= ny && ny < h) {
			if (board[nx][ny] == 0) continue;
			board[nx][ny] = 0;
			dfs(nx, ny);
		}
	}
}
int main() {
	cin >> h >> w;
	while (w != 0 && h != 0) {
		int cnt = 0;
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++)
				cin >> board[i][j];
		}
		for (int i = 0; i < w; i++) {
			for (int j = 0; j < h; j++)
				if (board[i][j] == 1) {
					board[i][j] = 0;
					dfs(i, j);
					cnt++;
				}
		}
		cout << cnt << '\n';
		cin >> h >> w;
	}

}