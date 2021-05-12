using namespace std;
#include <iostream>

int n, m;
char board[20][20];

struct coin {
	int x;
	int y;
};

int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };

int solution(int x1, int y1, int x2, int y2, int cnt) {
	if (cnt > 10) return -1;
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true;
	if (fall1 && fall2) return -1;
	if (fall1 || fall2) return cnt;

	int ans = -1;

	//0:µ¿, 1:¼­, 2:³², 3:ºÏ
	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + direction[i][0];
		int ny1 = y1 + direction[i][1];
		int nx2 = x2 + direction[i][0];
		int ny2 = y2 + direction[i][1];

		if ((0 <= nx1 && nx1 < n) && (0 <= ny1 || ny1 < n)) {
			if (board[nx1][ny1] == '#') {
				nx1 = x1;
				ny1 = y1;
			}
		}

		if ((0 <= nx2 && nx2 < n) && (0 <= ny2 || ny2 < n)) {
			if (board[nx2][ny2] == '#') {
				nx2 = x2;
				ny2 = y2;
			}
		}

		int temp = solution(nx1, ny1, nx2, ny2, cnt + 1);
		if (temp == -1) continue;
		if (ans == -1 || ans > temp)
			ans = temp;
	}
	return ans;
}
int main() {
	int x1 = -1, y1, x2, y2;
	int c = 0;
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			board[i][j] = x;
			if (board[i][j] == 'o') {
				if (x1 == -1) {
					x1 = i;
					y1 = j;
				}
				else {
					x2 = i;
					y2 = j;
				}
			}
		}
	}

	cout << solution(x1, y1, x2, y2, 0) << '\n';
}