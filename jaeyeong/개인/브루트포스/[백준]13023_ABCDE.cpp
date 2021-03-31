using namespace std;
#include <iostream>
#include <vector>

int n, m;
vector<int> fr[2000];
int visit[2000];
bool done = false;

void dfs(int p, int cnt) {
	if (cnt == 4) done = true;
	for (int i = 0; i < fr[p].size(); i++) {
		if (visit[fr[p][i]] == false) {
			visit[fr[p][i]] = true;
			dfs(fr[p][i], cnt+1);
			if (done == true) return;
			visit[fr[p][i]] = false;
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		visit[i] = true;
		dfs(i, 0);
		if (done == true) return;
		visit[i] = false;
	}
}
int main() {
	int x, y;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		fr[x].push_back(y);
		fr[y].push_back(x);
	}

	solve();
	if (done == true) cout << 1 << '\n';
	else cout << 0 << '\n';
	return 0;
}