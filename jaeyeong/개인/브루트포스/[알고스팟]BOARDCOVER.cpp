using namespace std;
#include <iostream>

int h, w;
int board[20][20];
const int coverType[4][3][2] = {
	{{0,0}, {1, 0}, {0, 1}},
	{{0, 0}, {0, 1}, {1, 1}},
	{{0, 0}, {1, 0}, {1, 1}},
	{{0, 0}, {1, 0}, {1, -1}}
};

bool inRange(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

bool set(int x, int y, int type, int delta) {
	bool res = true;
	for (int i = 0; i < 3; i++) {
		int nx = x + coverType[type][i][0];
		int ny = y + coverType[type][i][1];
		if (!inRange(nx, ny)) res = false;
		else if ((board[nx][ny] += delta) > 1) res = false;
	}
	return res;
}
int solve() {
	int x = -1, y = -1;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (board[i][j] == 0) {
				x = i;
				y = j;
				break;
			}
		}
		if (y != -1) break;
	}
	if (y == -1) return 1;
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		if (set(x, y, type, 1)) {
			ret += solve();
		}
		//백트래킹
		set(x, y, type, -1);
	}
	return ret;
}
int main() {
	char x;
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> h >> w;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> x;
				if (x == '.') board[i][j] = 0;
				else board[i][j] = 1;
			}
		}
		int ans = solve();
		cout << ans << '\n';
	}
}