using namespace std;
#include <iostream>
#include <vector>

int n, m, h;
int answer = 0x3f3f3f3f;
int ladder[31][11];

bool isFinished() {
	int x, y;
	for (int i = 1; i <= n; i++) {
		x = 1;
		y = i;
		while (x <= h) {
			if (ladder[x][y] != 0) {
				if (y != n && ladder[x][y + 1] == ladder[x][y]) y++;
				else if (y != 1 && ladder[x][y - 1] == ladder[x][y]) y--;
			}
			x++;
		}
		if (y != i) return false;
	}
	return true;
}
void solve(int a, int b, int cnt) { //a가로선에서 b~b+1 세로선을 이을 차레
	if (cnt == 5) return;
	if (isFinished() == true) {
		answer = min(answer, cnt-1);
		return;
	}
	for (int i = a; i <= h; i++) {

		for (int j = 1; j < n; j++) {
			if (ladder[i][j] != 0 || ladder[i][j+1]!=0) continue;
			ladder[i][j] = cnt;
			ladder[i][j + 1] = cnt;
			if (j + 1 == n) solve(i + 1, 1, cnt + 1);
			else solve(i, j + 2, cnt + 1);
			ladder[i][j] = 0;
			ladder[i][j+1] = 0;
		}
	}
}
int main() {
	int x, y;
	int l = -1;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		ladder[x][y] = l;
		ladder[x][y + 1] = l--;
	}
	solve(1, 1, 1);
	if(answer==0x3f3f3f3f) answer=-1;
	if (answer > 3) answer = -1;
	cout << answer << '\n';
}