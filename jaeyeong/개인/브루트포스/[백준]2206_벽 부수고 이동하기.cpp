using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int n, m;
int board[1000][1000], dist[1000][1000][2];

int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void bfs() {
	int answer = 0x3f3f3f3f;
	bool done = false;
	queue<tuple<int,int,int>> q;

	q.push(make_tuple(0,0,0));
	dist[0][0][0] = 1;
	while (!q.empty()) {
		int x, y, z;
		tie(x,y,z) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (dist[nx][ny][z] == 0 && board[nx][ny]==0) {
					dist[nx][ny][z] = dist[x][y][z] + 1;
					q.push(make_tuple(nx,ny,z));
				}
			}
			if (z == 0 && board[nx][ny] == 1 && dist[nx][ny][z + 1] == 0) {
				dist[nx][ny][z + 1] = dist[x][y][z] + 1;
				q.push(make_tuple(nx, ny, z + 1));
			}
		}
	}

	if (dist[n - 1][m - 1][0] != 0 && dist[n - 1][m - 1][1] != 0) {
		cout << min(dist[n - 1][m - 1][0], dist[n - 1][m - 1][1]);
	}
	else if (dist[n - 1][m - 1][0] != 0) {
		cout << dist[n - 1][m - 1][0];
	}
	else if (dist[n - 1][m - 1][1] != 0) {
		cout << dist[n - 1][m - 1][1];
	}
	else {
		cout << -1;
	}
	cout << '\n';

	return;
}
int main() {
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			board[i][j] = x-'0';
		}
	}

	bfs();

	return 0;
}