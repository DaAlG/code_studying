using namespace std;
#include <iostream>
#include <vector>

int n, m;
int arr[9],visited[9];
void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 1; i <= m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[cnt+1] = i;
			dfs(cnt + 1);
			visited[i] = false;
		}
	}
}
int main() {
	cin >> n >> m;
	dfs(0);
}