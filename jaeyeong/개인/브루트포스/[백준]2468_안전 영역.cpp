using namespace std;
#include <iostream>
#include <queue>
#include <cstring>

int n;
int region[100][100];
int visit[100][100];
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

void bfs(int a, int b, int k) {
	queue<pair<int, int>> q;
	visit[a][b] = true;
	q.push(make_pair(a, b));
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (visit[nx][ny] == false && region[nx][ny] > k) {
					visit[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	return;
}
int main() {
	int maxValue = -1;
	int maxCnt = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> region[i][j];
			if (region[i][j] > maxValue) maxValue = region[i][j];
		}
	}
	for (int k = 0; k <= maxValue; k++) {
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == false && region[i][j] > k) {
					bfs(i, j, k);
					cnt++;
				}
			}
		}
		memset(visit, false, sizeof(visit));
		if (cnt > maxCnt) maxCnt = cnt;
	}
	cout << maxCnt << '\n';
}