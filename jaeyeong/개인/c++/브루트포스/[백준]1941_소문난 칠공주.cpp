using namespace std;
#include <iostream>
#include <queue>
#include <vector>

char board[5][5];
bool visit[25];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer;
vector<pair<int, int>> v;

bool inRange(int x, int y) {
	return 0 <= x && x < 5 && 0 <= y && y < 5;
}

bool check_near() {
	queue<pair<int, int>> q;
	bool flag[7] = { false, };
	int x = v[0].first;
	int y = v[0].second;
	q.push(make_pair(x, y));
	flag[0] = true;
	int cnt = 1;
	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();
		for (int i = 1; i < 7; i++) {
			if (flag[i]) continue;
			for (int k = 0; k < 4; k++) {
				int nx = cx + dx[k];
				int ny = cy + dy[k];
				if (nx == v[i].first && ny == v[i].second) {
					q.push(make_pair(nx, ny));
					flag[i] = true;
					cnt++;
				}
			}
		}
	}
	if (cnt == 7) return true;
	return false;
}
void solve(int idx, int cnt, int cntS) {
	if (cnt == 7) {
		if (cntS >= 4) {
			if (check_near())
				answer++;
		}
		return;
	}
	for (int i = idx; i < 25; i++) {
		if (!visit[i]) {
			visit[i] = true;
			int x = i / 5;
			int y = i % 5;
			int s = 0;
			v.push_back(make_pair(x, y));
			if (board[x][y] == 'S') s = 1;
			solve(i+1, cnt + 1, cntS + s);
			visit[i] = false;
			v.pop_back();
		}
	}
}
int main() {
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> board[i][j];

	solve(0,0,0);
	cout << answer << '\n';
	return 0;
}