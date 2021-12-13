using namespace std;
#include <iostream>
#include <string.h>

int n, m, k;
int board[40][40];
int stickers[100][40][40];
int sticker_size[100][2];


void putOnBoard(int sn, int x, int y) {
	int sizeX = sticker_size[sn][0];
	int sizeY = sticker_size[sn][1];
	for (int i = x; i < x + sizeX; i++) {
		for (int j = y; j < y + sizeY; j++) {
			if (stickers[sn][i - x][j - y] == 1)
				board[i][j] = 1;
		}
	}
}
bool checkSticker(int sn, int x, int y) {
	int sizeX = sticker_size[sn][0];
	int sizeY = sticker_size[sn][1];
	for (int i = x; i < x + sizeX; i++) {
		for (int j = y; j < y + sizeY; j++) {
			if (stickers[sn][i - x][j - y] == 1 && board[i][j] == 1)
				return false;
		}
	}
	return true;
}
bool putSticker(int sn) {
	bool flag = false;
	int endN = n - sticker_size[sn][0];
	int endM = m - sticker_size[sn][1];
	for (int i = 0; i <= endN; i++) {
		for (int j = 0; j <= endM; j++) {
			if (checkSticker(sn, i, j)) {
				putOnBoard(sn, i, j);
				return true;
			}
		}
	}
	return false;
}

void rotate90(int sn) {
	int sizeX = sticker_size[sn][0];
	int sizeY = sticker_size[sn][1];
	int temp[40][40] = { 0 };
	for (int i = 0; i < sizeY; i++) {
		for (int j = 0; j < sizeX; j++) {
			temp[i][j] = stickers[sn][sizeX - j - 1][i];
		}
	}
	swap(sticker_size[sn][0], sticker_size[sn][1]);
	memmove(stickers[sn], temp, sizeof(stickers[sn]));
	return;
}
int main() {
	cin >> n >> m >> k;
	for(int i=0;i<k;i++) {
		cin >> sticker_size[i][0] >> sticker_size[i][1];
		for (int x = 0; x < sticker_size[i][0]; x++) {
			for (int y = 0; y < sticker_size[i][1]; y++) {
				cin >> stickers[i][x][y];
			}
		}
	}
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < 4; j++) {
			if (j != 0) rotate90(i);
			if(putSticker(i)) break;
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1) answer++;
		}
	}
	cout << answer << '\n';
}