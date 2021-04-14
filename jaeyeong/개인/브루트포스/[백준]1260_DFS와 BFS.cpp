using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

int n, m, v;
vector<int> graph[1001];
bool visit[1001] = { 0 };

void dfs(int x) {
	if (visit[x]) {
		return;
	}
	visit[x] = true;
	cout << x << ' ';
	for (int i = 0; i < graph[x].size(); i++) {
		dfs(graph[x][i]);
	}
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = true;
	while (!q.empty()) {
		int c = q.front();
		cout << c << ' ';
		q.pop();
		for (int i = 0; i < graph[c].size(); i++) {
			if (!visit[graph[c][i]]) {
				visit[graph[c][i]] = true;
				q.push(graph[c][i]);
			}
		}
	}
}
int main() {
	int x, y;

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(v);
	memset(visit, false, sizeof(visit));
	cout << '\n';
	bfs(v);
}