using namespace std;
#include <iostream>

int n, s, answer;
bool visit[20];
int arr[20] = {0}, ans[20];

int sum(int m) {
	int a = 0;
	for (int i = 0; i < m; i++)
		a += ans[i];
	return a;
}
void combination(int m, int cnt, int idx) {
	if (m == cnt) {
		if (sum(m) == s) answer++;
		return;
	}
	for (int i = idx; i < n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			ans[cnt] = arr[i];
			combination(m, cnt + 1, i + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 1; i <= n; i++)
		combination(i, 0, 0);
	cout << answer << '\n';
}