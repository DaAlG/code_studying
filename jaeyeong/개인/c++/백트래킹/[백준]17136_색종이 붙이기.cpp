using namespace std;
#include <iostream>

int board[10][10];
int n;
const int MAX = 10;
int answer = 0x3f3f3f3f;
int papers[6];

bool possible_attach(int x, int y, int psize) {
	//psize: 붙일 종이 사이즈
	for (int i = 0; i < psize; i++) {
		for (int j = 0; j < psize; j++) {
			if (!board[x + i][y + j])
				return false;
		}
	}
	return true;
}

void update_paper(int x, int y, int psize, bool is_attach) {
	for (int i = 0; i < psize; i++) {
		for (int j = 0; j < psize; j++) {
			board[x + i][y + j] = is_attach;
		}
	}
}
void solve(int x, int y, int cnt) {
	//1. 1을 찾을 때까지 증가
	while (board[x][y] == 0) {
		if (++y >= MAX) {
			if (++x >= MAX) {
				answer = min(answer, cnt);
				return;
			}
			y = 0;
		}
	}
	//2. 가지 치기
	if (answer <= cnt)
		return;

	//3. 종이 종류별로 붙여보기
	for (int s = 5; s > 0; s--) {
		if (x + s > MAX || y + s > MAX || papers[s] == 5) continue;

		if (possible_attach(x, y, s)) {
			//부착
			update_paper(x, y, s, 0);
			papers[s]++;
			solve(x, y, cnt + 1);
			//제거 (백트래킹)
			update_paper(x, y, s, 1);
			papers[s]--;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) n++;
		}
	}
	if (n == MAX*MAX) {
		cout << "4\n";
		return 0;
	}
	solve(0,0,0);
	if (answer == 0x3f3f3f3f) answer = -1;
	cout << answer << '\n';
	return 0;
}