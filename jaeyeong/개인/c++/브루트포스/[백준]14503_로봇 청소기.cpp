using namespace std;
#include <iostream>
#include <tuple>

//0:북, 1:동, 2:남, 3:서
int dir[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int board[50][50], visit[50][50]; //visit 0~4방향, -1안간곳 -100 벽
int n, m;
bool done = false;
/*
void printVisit() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(visit[i][j]==-100)
				cout << "★" << '\t';
			else if(visit[i][j]==-1)
				cout << "☆" << '\t';
			else
			cout << visit[i][j] << '\t';
		}
		cout << '\n';
	}
	cout << "----------------------------------------------\n";
}
*/
bool checkWhole(int x, int y) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || n <= nx || ny < 0 || m <= ny)
			continue;
		if (visit[nx][ny] == -1)
			cnt++;
	}
	if (cnt == 0) return false; //갈 수 있는 곳이 없다
	else return true; //안간 곳이 있다.
}
pair<int,int> dfs(int x, int y, int d) {
	int nextD = d, lastD;
	while (checkWhole(x,y) == false) {
		if (2 <= d)
			nextD = d - 2;
		else
			nextD = d + 2;
		int nx = x + dir[nextD][0];
		int ny = y + dir[nextD][1];
		if ((board[nx][ny] == 1) || (nx < 0 || n <= nx || ny < 0 || m <= ny)) {
			done = true;
			return make_pair(x, y);
		}
		visit[nx][ny] = d;
		if (checkWhole(nx, ny) == true) {
			return make_pair(nx, ny);
		}
		x = nx;
		y = ny;
	}

	for (int i = 0; i < 4; i++) {
		nextD -= 1;
		if (nextD == -1) nextD = 3;
		int nx = x + dir[nextD][0];
		int ny = y + dir[nextD][1];
		if (nx < 0 || n <= nx || ny < 0 || m <= ny)
			continue;
		if (visit[nx][ny]==-1) {
			visit[nx][ny] = nextD;
			//printVisit();
			tie(x,y) = dfs(nx, ny, nextD);
			if (done == true) break;
			d = visit[x][y];
			nextD = d;
			i = 0;
		}
	}
	return make_pair(x, y);
}
int main() {
	int r, c, d;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) visit[i][j] = -100;
			else visit[i][j] = -1; //
		}
	}
	visit[r][c] = d;
	dfs(r,c, d);

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (visit[i][j] >= 0) ans++;
		}
	}
	cout << ans << '\n';
}