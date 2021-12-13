using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n, m;
vector<int> v;
int arr[9];
bool visit[10001];

void comb(int idx, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = idx; i < n; i++) {
		if (!visit[v[i]]) {
			visit[v[i]] = true;
			arr[cnt] = v[i];
			comb(i + 1, cnt + 1);
			visit[vQ[i]] = false;
		}
	}
}
int main() {
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	comb(0, 0);
}