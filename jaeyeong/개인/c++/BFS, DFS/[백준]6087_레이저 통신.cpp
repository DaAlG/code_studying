using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int w, h;
char board[100][100];
vector<pair<int, int>> lc;
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int visit[100][100];

bool inRange(int x, int y) {
	return 0 <= x && x < w && 0 <= y && y < h;
}

void bfs() {
	queue<pair<int, int>> q; //x,y,오던방향,거울갯수
	visit[lc[0].first][lc[0].second] = 1;
	q.push(make_pair(lc[0].first, lc[0].second));
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x, ny = y;
			while (1) {
				nx += dir[i][0];
				ny += dir[i][1];

				if (!inRange(nx, ny)) break;
				if (board[nx][ny] == '*') break;;

				if (visit[nx][ny]==0) {
					visit[nx][ny] = visit[x][y] + 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}

	cout << visit[lc[1].first][lc[1].second]-2 << '\n';
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> h >> w;
	char x;
	int c_cnt = 0;
	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			cin >> x;
			board[i][j] = x;
			if (board[i][j] == 'C') {
				lc.push_back(make_pair(i, j));
			}
		}
	}
	bfs();
}