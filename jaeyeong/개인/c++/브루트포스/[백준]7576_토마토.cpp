using namespace std;
#include <iostream>
#include <queue>

int n, m; //m¿Ã x, n¿Ã y
int board[1001][1001];
queue<pair<int,int>> q;
int direction[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };

int bfs() {
	int cnt = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (board[x][y] > cnt) cnt++;
		for (int i = 0; i < 4; i++) {
			int mx = x + direction[i][0];
			int my = y + direction[i][1];
			if (0 < mx && mx <= m && 0 < my && my <= n) {
				if (board[mx][my] > 0) continue;
				if (board[mx][my] == -1) continue;
				q.push(make_pair(mx, my));
				board[mx][my] = cnt + 1;
			}
		}
	}
	return cnt;
}

bool check() {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 0) {
				return false;
			}
		}
	}
	return true;
}
int main() {
	int cnt = 1;
	bool able=true;
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	int result = bfs() - 1;
	if(check()==true)
		cout<<result<<'\n';
	else
		cout << -1 << '\n';
	return 0;
}