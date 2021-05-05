using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <tuple>

int n,l,r;
int map[101][101], visit[101][101];
int dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
int cnt = 1;

bool check() {
	int c = map[0][0];

	bool possible = false, same = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (same==true && map[i][j] != c)
				same = false;
			for (int k = 0; k < 4; k++) {
				if (possible == true) continue;

				int nx = i + dir[k][0];
				int ny = j + dir[k][1];
				if (nx < 0 || nx >= n) continue;
				if (ny < 0 || ny >= n) continue;

				int dif = map[i][j] - map[nx][ny];
				if (dif < 0) dif *= -1;

				if (l <= dif && dif <= r)
					possible = true;
			}
		}
	}
	if (possible == false || same==true)
		return true;

	return false;
}

bool available(int a, int b) {
	for (int i = 0; i < 4; i++) {
		int nx = a + dir[i][0];
		int ny = b + dir[i][1];
		if (nx < 0 || nx >= n) continue;
		if (ny < 0 || ny >= n) continue;
		int dif = map[a][b] - map[nx][ny];
		if (dif < 0) dif *= -1;
		if (l <= dif && dif <= r)
			return true;
	}
	return false;
}

void search() {
	queue<pair<int, int>> q;
	int cx, cy;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (available(i, j) == false) continue;
			if (visit[i][j] == 0) {
				q.push(make_pair(i, j));
				visit[i][j] = cnt++;
			}
			while (!q.empty()) {
				tie(cx, cy) = q.front();
				q.pop();
				for (int k = 0; k < 4; k++) {
					int nx = cx + dir[k][0];
					int ny = cy + dir[k][1];
					if (nx < 0 || nx >= n) continue;
					if (ny < 0 || ny >= n) continue;
					if (visit[nx][ny] > 0) continue;

					int dif = map[cx][cy] - map[nx][ny];
					if (dif < 0) dif *= -1;
					if (l <= dif && dif <= r) {
						visit[nx][ny] = visit[cx][cy];
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}



void move() {
	vector<pair<int,int>> v[3000];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visit[i][j] != 0) {
				v[visit[i][j]].push_back(make_pair(i, j));
			}
		}
	}
	for (int i = 1; i < cnt; i++) {
		int sum = 0;
		int m = v[i].size();
		for (int j = 0; j < m; j++) {
			sum += map[v[i][j].first][v[i][j].second];
		}
		for (int j = 0; j < m; j++) {
			map[v[i][j].first][v[i][j].second] = sum / m;
		}
	}
}

void print() {
	cout << "-------visit-------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << "--------map--------\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << map[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	int answer = 0;
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	while (!check()) {
		cnt = 1;
		memset(visit, 0, sizeof(visit));
		search();
		move();
		//print();
		answer++;
	}
	cout << answer << '\n';
	return 0;
}