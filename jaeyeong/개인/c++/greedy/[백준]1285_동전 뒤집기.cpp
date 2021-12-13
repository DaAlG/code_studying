using namespace std;
#include <iostream>

int n;
char board[20][20];
char visit[20][20][2];

char turn(char x) {
	if (x == 'H') return 'T';
	else return 'H';
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	int ans = n * n;
	//행을 바꿀지 말지 비트마스크로 알아차림
	for (int state = 0; state < (1 << n); state++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				char cur = board[i][j];
				if (state & (1 << i)) {
					cur = turn(cur);
				}
				if (cur == 'T')
					cnt++;
			}
			sum += min(cnt, n - cnt);
		}
		ans = min(sum, ans);
	}
	cout << ans << '\n';
	return 0;
}