using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#define MAX 200

int k;
int w, h;
int board[MAX][MAX];
int visit[MAX][MAX][31];
int dx[12] = { 0,0,1,-1, -2,-1,1,2,2,1,-1,-2 }; //0~4:동서남북 나머지:나이트
int dy[12] = { 1,-1,0,0,1,2,2,1,-1,-2,-2,1 };

bool inRange(int x, int y) {
	return 0 <= x && x < h && 0 <= y && y < w;
}

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(0, 0, 0));
	visit[0][0][0] = 1;
	while (!q.empty()) {
		int x, y, cnt;
		tie(x, y, cnt) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inRange(nx, ny)) continue;
			if (visit[nx][ny][cnt] || board[nx][ny]==1) continue;
			visit[nx][ny][cnt] = visit[x][y][cnt]+1;
			q.push(make_tuple(nx, ny, cnt));
		}
		if (cnt == k) continue;
		for (int i = 4; i < 12; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inRange(nx, ny)) continue;
			if (visit[nx][ny][cnt+1] || board[nx][ny] == 1) continue;
			visit[nx][ny][cnt+1] = visit[x][y][cnt] + 1;
			q.push(make_tuple(nx, ny, cnt+1));
		}
	}
	int answer = -1;
	for (int i = 0; i <= k; i++) {
		if (visit[h - 1][w - 1][i] != 0) {
			if (answer == -1) answer = visit[h - 1][w - 1][i];
			else answer = min(answer, visit[h - 1][w - 1][i]);
		}
	}
	if (answer == -1) return answer;
	return answer - 1;
}

int main() {
	cin >> k;
	cin >> w >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			cin >> board[i][j];
	int answer = bfs();
	cout << answer << '\n';
	return 0;
}