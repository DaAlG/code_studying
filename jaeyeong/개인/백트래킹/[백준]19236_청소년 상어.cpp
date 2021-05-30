using namespace std;
#include <iostream>
#include <tuple>
#include <cstring>

// 북부터 시계방향으로 1,2,3,4 ,,,
int board[4][4]; // 1~16: 물고기, 0: shark, -1:죽은 물고기
int fish[17][2]; //위치, 방향
int answer = -1;


pair<int, int> direction(int x, int y, int d) {
	switch (d) {
	case 1: x -= 1;
		break;
	case 2: x -= 1; y -= 1;
		break;
	case 3: y -= 1;
		break;
	case 4: x += 1; y -= 1;
		break;
	case 5: x += 1;
		break;
	case 6: x += 1; y += 1;
		break;
	case 7: y += 1;
		break;
	case 8: x -= 1; y += 1;
		break;
	}
	return make_pair(x, y);
}

bool inRange(int x, int y) {
	return 0 <= x && x < 4 && 0 <= y && y < 4;
}

void moveFish() {
	for (int i = 1; i <= 16; i++) {
		if (fish[i][0] == -1) continue; //죽은 물고기
		int x=fish[i][0]/4, y=fish[i][0]%4, nx=x, ny=y;
		int cnt = 0;
		while (1) {
			tie(nx, ny) = direction(x, y, fish[i][1]);
			if (!inRange(nx, ny) || board[nx][ny]==0) {
				if (++cnt == 8) break;
				fish[i][1]++;
				if (fish[i][1] == 9) fish[i][1] = 1;
			}
			else {
				if (board[nx][ny] != -1)
					swap(fish[board[x][y]][0], fish[board[nx][ny]][0]);
				else
					fish[board[x][y]][0] = nx * 4 + ny;
				swap(board[x][y], board[nx][ny]);
				break;
			}
		}
	}
}
void solve(int x, int y, int d, int sum) {
	int dup[4][4];
	int fdup[17][2];
	int nx = x, ny = y;

	for (int i = 1; i <= 16; i++) {
		fdup[i][0] = fish[i][0];
		fdup[i][1] = fish[i][1];
	}
	memcpy(dup, board, sizeof(dup));

	moveFish();
	while (1) {
		tie(nx, ny) = direction(nx, ny, d);
		if (inRange(nx, ny)) {
			//shark moves and eat
			int idx = board[nx][ny];
			if (idx == -1) continue; //물고기 없음
			board[x][y] = -1;
			board[nx][ny] = 0;
			fish[idx][0] = -1;
			int sharkD = fish[idx][1];
			solve(nx, ny, sharkD, sum + idx);

			//복구
			board[x][y] = 0;
			board[nx][ny] = idx;
			fish[idx][0] = 4 * nx + ny;
		}
		else break;
	}
	answer = max(answer, sum);
	//복구
	memcpy(board, dup, sizeof(dup));
	for (int i = 1; i <= 16; i++) {
		fish[i][0] = fdup[i][0];
		fish[i][1] = fdup[i][1];
	}
	return;
}
int main() {
	int x, y;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> x >> y;
			board[i][j] = x;
			fish[x][0] = 4 * i + j;
			fish[x][1] = y;
		}
	}

	int initN = board[0][0];
	int initD = fish[initN][1];
	fish[initN][0] = -1;
	board[0][0] = 0;
	solve(0,0,initD,initN);
	cout << answer << '\n';
}