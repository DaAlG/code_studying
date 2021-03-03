using namespace std;
#include <iostream>
#include <vector>

int available[2001][2001] = { 0 };
int board[2001] = { 0 };

void setPalin(int n) {
	//i는 길이 = y-x

	//길이 1
	for (int i = 1; i <= n; i++)
		available[i][i] = 1;
	//길이 2
	for (int i = 1; i < n; i++) {
		if(board[i]==board[i+1])
			available[i][i+1] = available[i+1][i] = 1;
	}
	//길이 3 이상
	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (available[j + 1][j + i - 1] == 1 && board[j] == board[j + i])
				available[j][j + i] = available[j+i][j] = 1;
		}
	}

}


int main() {
	int n, m;
	int x, y;

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> board[i];
		available[i][i] = 1;
	}

	setPalin(n);

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		cout << available[x][y] << '\n';
	}
	return 0;
}