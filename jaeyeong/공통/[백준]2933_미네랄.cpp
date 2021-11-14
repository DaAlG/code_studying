using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
#define MAX 100
#define INF 0x3f3f3f3f
#define left 1
#define right -1

int r, c;
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
vector<string> board;
vector<pair<int, int>> air_cluster;
vector<int> order;
bool visit[MAX][MAX];
bool clusterBoard[MAX][MAX];

bool inRange(int x, int y) {
	return 0 <= x && x < r && 0 <= y && y < c;
}

bool throw_stick(int height, int direction) {
	int idx = direction==left ? 0 : c-1;
	int end = direction == left ? c : -1;
	int add = direction == left ? 1 : -1;
	while (idx != end) {
		if (board[height][idx] == 'x') {
			board[height][idx] = '.';
			return true;
		}
		idx += add;
	}
	return false;
}

void bfs(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push(make_pair(sx, sy));
	visit[sx][sy] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + direction[i][0];
			int ny = y + direction[i][1];
			if (inRange(nx, ny) && board[nx][ny] == 'x' && !visit[nx][ny]) {
				visit[nx][ny] = true;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
bool cluster_in_air() {
	for (int i = 0; i < c; i++) {
		//땅바닥의 미네랄만
		if (board[r - 1][i] == 'x' && !visit[r - 1][i])
			bfs(r - 1, i);
	}
	bool flag = false;
	memset(clusterBoard, false, sizeof(clusterBoard));
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (board[i][j] == 'x' && visit[i][j] == false) {
				flag = true;
				clusterBoard[i][j] = true;
				air_cluster.push_back(make_pair(i, j));
			}
		}
	}
	return flag;
}
int fallRes(int x, int y) {
	int res = 0;
	for (int i = x + 1; i < r; i++) {
		if (board[i][y] == 'x') {
			if (clusterBoard[i][y] == true) return INF;
			else return res;
		}
		else if (board[i][y] == '.') res++;
	}
	return res;
}

void update_map() {
	int desH = INF;
	for (int i = 0; i < air_cluster.size(); i++) {
		int x = air_cluster[i].first;
		int y = air_cluster[i].second;
		int t = fallRes(x, y);
		if (t == INF) continue;
		else desH = min(t, desH);
	}
	sort(air_cluster.begin(), air_cluster.end());
	for (int i = air_cluster.size() - 1; 0 <= i; i--) {
		int x = air_cluster[i].first;
		int y = air_cluster[i].second;
		board[x][y] = '.';
		board[x + desH][y] = 'x';
	}
}
void solution() {
	//direction 1=left, -1=right
	//처음 방향을 left로 하기 위해 right로 초기화
	int direction = right;
	for (int i = 0; i < order.size(); i++) {
		air_cluster.clear();
		memset(visit, false, sizeof(visit));
		memset(clusterBoard, false, sizeof(visit));
		direction *= -1;
		if (!throw_stick(r-order[i], direction)) continue;
		if (!cluster_in_air()) continue;
		else update_map();
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << board[i][j];
		}
		cout << '\n';
	}
}
int main() {
	cin >> r >> c;
	board.resize(r);
	for (int i =0; i<r; i++)
		cin >> board[i];
	int n;
	cin >> n;
	order.resize(n);
	for (int i = 0; i < n; i++)
		cin >> order[i];
	solution();
}