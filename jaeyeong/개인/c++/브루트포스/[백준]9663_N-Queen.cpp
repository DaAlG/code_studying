using namespace std;
#include <iostream>

int n, answer;
int board[16][16],visit[16][16];

bool able(int x, int y) {
	int i, j;
	for (i = 1; i <= x; i++)//xÃà
		if (visit[i][y] == true) return false;
	for (i = 1; i <= y; i++)//yÃà
		if (visit[x][i] == true) return false;

	i = x - 1; j = y - 1;
	while (0 < i && 0 < j) {
		if (visit[i--][j--] == true) return false;
	}
	i = x - 1; j = y + 1;
	while (0 < i && j <= n) {
		if (visit[i--][j++] == true) return false;
	}

	return true;
}
bool check() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (board[i][j] == 0)
				return false;
	}
	return true;
}
void nqueen(int cnt) {
	if (cnt == n) {
		answer++;
		return;
	}
	int i = cnt + 1;
	for (int j = 1; j <= n; j++) {
		if (visit[i][j] == false && able(i,j)==true) {
			visit[i][j] = true;
			board[i][j] = 1;
			nqueen(cnt + 1);
			visit[i][j] = false;
		}
	}
}
int main() {
	cin >> n;
	nqueen(0);
	cout << answer << '\n';
}