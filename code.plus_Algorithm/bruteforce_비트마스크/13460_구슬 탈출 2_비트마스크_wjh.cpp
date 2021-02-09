#include <iostream>
#include <vector>
#include <string>

using namespace std;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
const int LIMIT = 10;

vector<int> gen(int k) {
	vector<int> a(LIMIT);
	for (int i = 0; i < LIMIT; i++) {
		a[i] = (k&3);
		k >>= 2;
	}
	return a;
}

pair<bool, bool> simulate(vector<string> &a, int k, int &x, int &y) {
	if (a[x][y] == '.')
		return make_pair(false, false);

	int n = a.size();
	int m = a[0].size();
	bool moved = false;

	while (true) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
			return make_pair(moved, false);
		}

		if (a[nx][ny] == '#') {
			return make_pair(moved, false);
		}
		else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') {
			return make_pair(moved, false);
		}
		else if (a[nx][ny] == '.') {
			swap(a[nx][ny], a[x][y]);
			x = nx;
			y = ny;
			moved = true;
		}
		else if (a[nx][ny] == '0') {
			a[x][y] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}
	return make_pair(false, false);
}

int check(vector<string> a, vector<int> &dir) {
	int n = a.size();
	int m = a[0].size();
	int hx, hy, rx, ry, bx, by;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '0') {
				hx = i; hy = j;
			}
			else if (a[i][j] == 'R') {
				rx = i; ry = j;
			}
			else if (a[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}

	int cnt = 0;
	for (int k : dir) {
		cnt += 1;
		bool hole1 = false, hole2 = false;

		while (true) {
			auto p1 = simulate(a, k, rx, ry);
			auto p2 = simulate(a, k, bx, by);

			if (p1.first == false && p2.first == false) {
				break;
			}

			if (p1.second) hole1 = true;
			if (p2.second) hole2 = true;
		}

		if (hole2) return -1;
		if (hole1) return cnt;
	}
	return -1;
}

bool valid(vector<int> &dir) {
	int l = dir.size();

	for (int i = 0; i + 1 < l; i++) {
		if (dir[i] == 0 && dir[i + 1] == 1) return false;
		if (dir[i] == 1 && dir[i + 1] == 0) return false;
		if (dir[i] == 2 && dir[i + 1] == 3) return false;
		if (dir[i] == 3 && dir[i + 1] == 2) return false;
		if (dir[i] == dir[i + 1]) return false;
	}
	return true;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = -1;
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
		vector<int> dir = gen(k);
		if (!valid(dir)) continue;

		int cur = check(a, dir);
		if (cur == -1) continue;
		if (ans == -1 || ans > cur) ans = cur;
	}

	cout << ans << endl;
	return 0;
}