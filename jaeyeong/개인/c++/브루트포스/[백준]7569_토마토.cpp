using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int m, n, h;
int box[100][100][100];
int dir[6][3] = { {0,1,0},{0,-1,0},{1,0,0},{-1,0,0},{0,0,1},{0,0,-1} };
int visit[100][100][100];

int bfs() {
	int ans = -1;
	queue<tuple<int, int, int>> q;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}
	while (!q.empty()) {
		int x, y, z;
		tie(z, x, y) = q.front();
		box[z][x][y] = 1;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			int nz = z + dir[i][2];
			if (0 > nx || n <= nx) continue;
			if (0 > ny || m <= ny) continue;
			if (0 > nz || h <= nz) continue;
			if (!visit[nz][nx][ny] && box[nz][nx][ny]==0) {
				visit[nz][nx][ny] = visit[z][x][y] + 1;
				q.push(make_tuple(nz, nx, ny));
			}
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
					ans = ans < visit[i][j][k] ? visit[i][j][k] : ans;
			}
		}
	}
	return ans;
}

bool check() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

bool checkFull() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0)
					return false;
			}
		}
	}
	return true;
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
			}
		}
	}
	if (checkFull() == true) {
		cout << "0\n";
		return 0;
	}

	int ans = bfs();
	if (check() == false) cout << "-1\n";
	else cout << ans << '\n';
	return 0;
}