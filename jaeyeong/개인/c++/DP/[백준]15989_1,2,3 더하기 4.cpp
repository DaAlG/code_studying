using namespace std;
#include <iostream>

void initBoard(int n, int board[][3]) {
	//1
	board[0][0] = 1;
	//2
	board[1][0] = 1;
	board[1][1] = 1;
	//3
	board[2][0] = 1;
	board[2][1] = 1;
	board[2][2] = 1;

	for (int i = 3; i < n; i++) {
		board[i][0] = board[i-1][0];
		board[i][1] = board[i - 2][0] + board[i - 2][1];
		board[i][2] = board[i - 3][0] + board[i - 3][1] + board[i - 3][2];
	}
}
int main() {
	int n, max = -1;
	int arr[10000] = { 0 }, board[10000][3] = { 0 };
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) max = arr[i];
	}

	initBoard(max, board);
	for (int i = 0; i < n; i++) {
		int sum = board[arr[i] - 1][0] + board[arr[i] - 1][1] + board[arr[i] - 1][2];
		cout << sum << '\n';
	}
}