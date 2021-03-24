using namespace std;
#include <iostream>
#include <queue>
#define INF 0x3f3f3f3f

int n, m;
char board[11][11];
int direction[4][2] = { {1,0},{-1,0},{0,-1}, {0,1}};
int min_value = INF;

pair<int, int> getPosition(int x, int y, int num) {
	int dx = direction[num][0];
	int dy = direction[num][1];
	while (1) {
		if (board[x + dx][y + dy] == '.' || board[x + dx][y + dy] == 'O') {
			x += dx;
			y += dy;
			if (board[x][y] == 'O') break;
		}
		else break;
	}

	return make_pair(x, y);
}
void solution(int rx, int ry, int bx, int by, int cnt, int dir) {
	if (board[bx][by]=='O') {
		return;
	}
	if (board[rx][ry] == 'O') {
		if (min_value > cnt) min_value = cnt;
		return;
	}
	if (cnt == 10) return;

	for (int i = 0; i < 4; i++) {
		if (i == 0 && dir == 1) continue;
		if (i == 1 && dir == 0) continue;
		if (i == 2 && dir == 3) continue;
		if (i == 3 && dir == 2) continue;

		pair<int, int> nr = getPosition(rx, ry, i);
		pair<int, int> nb = getPosition(bx, by, i);
 		int nrx = nr.first;
		int nry = nr.second;

		int nbx = nb.first;
		int nby = nb.second;

		if (nrx==nbx && nry == nby) {
			if (board[nrx][nry] == 'O') {
				solution(nrx, nry, nbx, nby, cnt + 1, i);
			}
			else if (ry == by && i < 3) {
				int* upper = rx < bx ? &nrx : &nbx; //더 위쪽인 것
				int* lower = rx < bx ? &nbx : &nrx; //더 아래쪽인 것
				if (i == 0)//아래로 움직일 때
					*upper -= 1;
				else //위로 움직일 때
					*lower += 1;
			}
			else if (rx == bx && i >= 2) {
				int* upper = ry < by ? &nry : &nby; //더 왼쪽인것
				int* lower = ry < by ? &nby : &nry; //더 오른쪽인 것
				if (i == 2)//왼쪽으로 움직일 때
					*lower += 1;
				else//오른쪽으로 움직일 때
					*upper -= 1;
			}
		}
		if (0 < nrx && nrx <= n && 0 < nry && nry <= m) {
			if (0 < nbx && nbx <= n && 0 < nby && nby <= m) {
				solution(nrx, nry, nbx, nby, cnt + 1, i);
			}
		}
	}
}
int main() {
	int rx, ry, bx, by;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'R') {
				rx = i;
				ry = j;
				board[i][j] = '.';
			}
			else if (board[i][j] == 'B') {
				bx = i;
				by = j;
				board[i][j] = '.';
			}
		}
	}

	solution(rx, ry, bx, by, 0, -1);
	if (min_value == INF)
		cout << "-1" << '\n';
	else
		cout << min_value << '\n';
	return 0;
}