using namespace std;
#include <iostream>

int rgb, rgbx;
int n;
int picture1[101][101], picture2[101][101];
int direction[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int r = 'R' - 'A', g = 'G' - 'A', b = 'B' - 'A';
int current;

void dfs1(int x, int y) {
	if (picture1[x][y] != current)
		return;
	
	picture1[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (0 < nx && nx <= n && 0 < ny && ny <= n) {
			if (picture1[nx][ny] == 0) continue;
			dfs1(nx, ny);
		}
	}
}

void dfs2(int x, int y) {
	if (picture2[x][y] != current) {
		if(picture2[x][y]==b || current == b)
			return;
	}

	picture2[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + direction[i][0];
		int ny = y + direction[i][1];
		if (0 < nx && nx <= n && 0 < ny && ny <= n) {
			if (picture2[nx][ny] == 0) continue;
			dfs2(nx, ny);
		}
	}
}



int main() {
	char input;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> input;
			picture1[i][j] = input- 'A';
			picture2[i][j] = input - 'A';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (picture1[i][j] == r || picture1[i][j] == g || picture1[i][j] == b) {
				current = picture1[i][j];
				dfs1(i, j);
				rgb++;
			}
			if (picture2[i][j] == r || picture2[i][j] == g || picture2[i][j] == b) {
				current = picture2[i][j];
				dfs2(i, j);
				rgbx++;
			}
		}
	}
	cout << rgb << ' ' << rgbx << '\n';
	
}