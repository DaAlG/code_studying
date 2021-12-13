using namespace std;
#include <iostream>

int n, m;
int arr[9],visit[9];

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = arr[cnt]+1; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr[cnt+1] = i;
			backtracking(cnt + 1);
			visit[i] = false;
		}

	}

}
int main() {
	cin >> n >> m;
	backtracking(0);
}