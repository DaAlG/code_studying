using namespace std;
#include <iostream>

int n, m;
int arr[8];
void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[cnt + 1] = i;
		backtracking(cnt + 1);
	}
}
int main() {
	cin >> n >> m;
	backtracking(0);
}