using namespace std;
#include <iostream>
#include <queue>
#include <tuple>

int board[1000][1000], visit[1000][1000][11], direction[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int n, m, k;

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (board[nx][ny] == 0) {
					if (!visit[nx][ny][z]) {
						visit[nx][ny][z] = visit[x][y][z] + 1;
						q.push(make_tuple(nx, ny, z));
					}
				}
				else if (board[nx][ny] == 1 && (z+1)<=k) {
					if (!visit[nx][ny][z + 1]) {
						visit[nx][ny][z + 1] = visit[x][y][z] + 1;
						q.push(make_tuple(nx, ny, z + 1));
					}
				}
			}
		}
	}
	int answer = 0x3f3f3f3f;
	for (int i = 0; i <= k; i++) {
		if (visit[n - 1][m - 1][i] != 0) {
			if (visit[n - 1][m - 1][i] < answer)
				answer = visit[n - 1][m - 1][i];
		}
	}

	if (answer == 0x3f3f3f3f)
		return -1;
	else
		return answer;
}
int main() {
	char x;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			board[i][j] = x - '0';
		}
	}
	cout << bfs() << '\n';
}