using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#include <tuple>

string board[5];
int n;
int dx[8] = { -1,-1,-1,1,1,1,0,0 };
int dy[8] = { -1,0,1,-1,0,1,-1,1 };

bool inRange(int x, int y) {
	return 0 <= x && x < 5 && 0 <= y && y < 5;
}

string solve(string tofind) {
	queue<tuple<int, int, int>> q; // (x,y,idx);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (tofind[0] == board[i][j])
				q.push(make_tuple(i, j, 0));
		}
	}
	while (!q.empty()) {
		int cx, cy, cidx;
		tie(cx, cy, cidx) = q.front();
		q.pop();
		if (cidx == tofind.size() - 1)
			return "YES";
		for (int i = 0; i < 8; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (!inRange(nx, ny)) continue;
			if (board[nx][ny] == tofind[cidx + 1])
				q.push(make_tuple(nx, ny, cidx + 1));
		}
	}
	return "NO";
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		for (int i = 0; i < 5; i++)
			cin >> board[i];
		cin >> n;
		vector<string> s(n);
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < n; i++) {
			string ans = solve(s[i]);
			cout << s[i] << ' ' << ans << '\n';
		}
	}
	return 0;
}