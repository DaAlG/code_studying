using namespace std;
#include <iostream>
#include <vector>
#include <queue>

int board[1000000] = {};

void maxCandy(int n, int m) {
	int start = m + 1;

	for (int i = start; i < n * m; i++) {
		if (i % m == 0) continue;
		board[i] += board[i - 1] > board[i - m] ? board[i - 1] : board[i - m];
	}
}

int main() {
	int n, m;

	cin >> n >> m;


	for (int i = 0; i < n * m; i++) {
		cin >> board[i];
	}

	for (int i = 1; i < m; i++) {
		board[i] += board[i - 1];
	}

	for (int i = m; i < n*m; i+=m) {
		board[i] += board[i - m];
	}

	maxCandy(n,m);
	cout << board[n*m-1] << '\n';
	return 0;
}