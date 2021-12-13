using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <tuple>
#define MAX 300

int n, m;
int board[MAX][MAX], sea[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void afterYear() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0)  continue;
			for (int k = 0; k < 4; k++) {
				if (board[i][j] == 0) break;
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (!inRange(nx, ny)) continue;
				if (sea[nx][ny] != 0) continue;
				board[i][j]--;
			}
		}
	}
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!inRange(nx, ny)) continue;
			if (!visit[nx][ny] && board[nx][ny] != 0) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

bool isIceberg() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (board[i][j] != 0) return true;
	return false;
}

int checkIceberg() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] != 0 && !visit[i][j]) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	if (cnt == 0) cnt = 1;
	return cnt;
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			sea[i][j] = board[i][j];
		}
	}


	int cnt = 1, answer = 0;
	cnt = checkIceberg();
	//이미 두 덩이 이상으로 분리된 경우
	if (cnt != 1) {
		cout << answer << '\n';
		return 0;
	}
	//매해 녹기 시작
	while (isIceberg() == true && cnt == 1) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		afterYear();
		cnt = checkIceberg();
		memcpy(sea, board, sizeof(sea));
		answer++;
	}
	if (cnt == 1) answer = 0;
	cout << answer << '\n';
}