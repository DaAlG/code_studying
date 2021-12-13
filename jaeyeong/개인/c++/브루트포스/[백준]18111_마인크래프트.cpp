using namespace std;
#include <iostream>
#define MAX 257

int board[500][500];
int height[MAX];
int n, m, blocks;
int minHeight = MAX, maxHeight = -1;
int main() {
	cin >> n >> m >> blocks;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			height[board[i][j]]++;
			if (board[i][j] < minHeight) minHeight = board[i][j];
			if (board[i][j] > maxHeight) maxHeight = board[i][j];
		}
	}
	if (maxHeight >= MAX) maxHeight = MAX-1;
	if (minHeight < 0) minHeight = 0;
	
	int ansTime=0x3f3f3f3f, ansHeight;
	for (int k = minHeight; k <= maxHeight; k++) {
		int myBlocks = blocks;
		int res = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] > k) { //2초걸림
					myBlocks += abs(board[i][j] - k);
					res += (2* abs(board[i][j] - k));
				}
				else if (board[i][j] < k) { //1초걸림
					myBlocks -= abs(board[i][j] - k);
					res += (1 * abs(board[i][j] - k));
				}
			}
		}
		if (myBlocks < 0) continue;
		if (ansTime >= res) {
			if (ansTime > res)
				ansTime = res;
			ansHeight = k;
		}
	}
	cout << ansTime << ' ' << ansHeight << '\n';
}