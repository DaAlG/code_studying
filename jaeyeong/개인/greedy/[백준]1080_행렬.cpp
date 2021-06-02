using namespace std;
#include <iostream>

int n, m;
int arr[50][50], brr[50][50];
bool flag = false;
bool visit[50][50];

bool inRange(int x, int y) {
	return (0 <= x && x < n && 0 <= y && y < m) &&
		(0 <= x + 2 && x + 2 < n && 0 <= y + 2 && y + 2 < m);
}
void turn(int x, int y) {
	for (int i = x; i < x + 3; i++) {
		for (int j = y; j < y + 3; j++) {
			if (arr[i][j] == 0) arr[i][j] = 1;
			else arr[i][j] = 0;
		}
	}
}
bool isSame() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] != brr[i][j]) return false;
	return true;
}
int solve() {
	int cnt = 0;
	if (n < 3 || m < 3) {
		if (isSame()) return 0;
		else return -1;
	}
	for (int i = 0; i <= n-3; i++) {
		for (int j = 0; j <= m-3; j++) {
			if (arr[i][j] != brr[i][j]) {
				turn(i, j);
				cnt++;
			}
			
			if (isSame() == true) {
				return cnt;
			}
			if (j == m - 3) {
				if ((arr[i][j] != brr[i][j]) ||
					(arr[i][j+1] != brr[i][j+1]) ||
					(arr[i][j+2] != brr[i][j+2]))
					return -1;
			}
		}
	}
	if (isSame() == true) return cnt;
	else return -1;
}
int main() {
	char x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			arr[i][j] = x - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			brr[i][j] = x - '0';
		}
	}
	int answer= solve();
	cout << answer << '\n';
}