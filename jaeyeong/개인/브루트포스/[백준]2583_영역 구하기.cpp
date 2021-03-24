using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int m, n, k;
int board[100][100];
int direction[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int c;

void dfs(int x, int y) {
	if (board[x][y] == 0) {
		board[x][y] = -1;
		c++;
		for (int i = 0; i < 4; i++) {
			int movex = x + direction[i][0];
			int movey = y + direction[i][1];
			if (movex >= 0 && movex < m && movey >= 0 && movey < n)
				dfs(movex, movey);
		}
	}
}
int main() {
	int x1, y1, x2, y2;
	vector<int> area;
	int x, y;

	cin >> m >> n >> k;
	while (k--) {
		cin >> x1 >> y1;
		cin >> x2 >> y2;

		for (int i = x1; i < x2; ++i) {
			for (int j = y1; j < y2; ++j) {
				board[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				dfs(i, j);
				area.push_back(c);
				c = 0;
			}
		}
	}

	sort(area.begin(), area.end());
	cout << area.size() << '\n';
	for (int i = 0; i < area.size(); i++)
		cout << area[i] << ' ';
	cout << '\n';

}