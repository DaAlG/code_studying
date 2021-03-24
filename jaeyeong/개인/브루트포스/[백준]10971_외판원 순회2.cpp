using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n;
int board[11][11];

int sum(vector<int> v) {
	int a = 0;
	for (int i = 1; i < n; i++) {
		if (board[v[i - 1]][v[i]] == 0)
			return -1;
		a += board[v[i - 1]][v[i]];
	}
	if(board[v[n-1]][v[0]]==0)
		return -1;
	a += board[v[n - 1]][v[0]];
	return a;
}

int main() {
	int ans = 0x3f3f3f3f;
	cin >> n;
	vector<int> v(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	}
	for (int i = 0; i < n; i++)
		v[i] = i + 1;
	do {
		int temp = sum(v);
		if (temp == -1) continue;
		if (temp < ans) ans = temp;
	} while (next_permutation(v.begin(), v.end()));
	cout << ans << '\n';
}