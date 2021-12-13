using namespace std;
#include <iostream>
#include <queue>

int r, c;
int visit[21][21], dir[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
char board[21][21];
int ans = -1;
bool visitAlpha[26];

void print() {
	for(int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << visit[i][j] << ' ';
		}
		cout << '\n';
	}
}
//visit�迭�� �Ÿ������� �ʿ���� ��Ʈ��ŷ ���ڿ� �Ÿ��� �����ϰ� �Ʒ� �ּ�ó�� �����ϸ� �� ����ϴ�
void backtracking(int x, int y) {
	/*
	* ans = max(ans,�Ÿ�);
	*/
	for (int i = 0; i < 4; i++) {
		int nx = x + dir[i][0];
		int ny = y + dir[i][1];
		if (nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
		if (!visit[nx][ny] && visitAlpha[board[nx][ny] - 'A'] == false) {
			visit[nx][ny] = visit[x][y] + 1;
			visitAlpha[board[nx][ny] - 'A'] = true;
			backtracking(nx, ny);
			visit[nx][ny] = 0;
			visitAlpha[board[nx][ny] - 'A'] = false;
		}
	}

	if (ans < visit[x][y])
		ans = visit[x][y];
	return;
}

int main() {
	char x;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> x;
			board[i][j] = x;
		}
	}

	visitAlpha[board[0][0] - 'A'] = true;
	visit[0][0] = 1;
	backtracking(0,0);
	cout << ans << '\n';
}