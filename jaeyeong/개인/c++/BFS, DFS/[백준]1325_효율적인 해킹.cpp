using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define MAX 10001

int n, m;
int maxCnt, cnt;
vector<int> v[MAX], ans;
bool visit[MAX];

void dfs(int x) {
	visit[x] = true;
	for (int i = 0; i < v[x].size(); i++) {
		if (!visit[v[x][i]]) {
			dfs(v[x][i]);
			cnt++;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		memset(visit, false, sizeof(visit));
		dfs(i);
		if (cnt > maxCnt) {
			maxCnt = cnt;
			ans.clear();
			ans.push_back(i);
		}
		else if (cnt == maxCnt) {
			ans.push_back(i);
		}
		cnt = 0;
	}
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << ' ';
	cout << '\n';
}