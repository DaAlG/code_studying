using namespace std;
#include <iostream>
#include <vector>

vector<int> graph[1001];
int visit[1001];
int n, m;

bool check() {
	for (int i = 1; i <= n; i++)
		if (visit[i] == 0)
			return false;
	return true;
}

void dfs(int k) {
	int next;
	if (visit[k] == 1)
		return;
	visit[k] = 1;
	int size = graph[k].size();
	for (int i = 0; i < size; i++) {
		if (graph[k].empty() == true) break;
		next = graph[k].back();
		graph[k].pop_back();
		dfs(next);
	}
	return;
}

int main() {
	int x, y, k=1, cnt=0;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	while (check() == false) {
		if (visit[k] == 0) {
			dfs(k);
			cnt++;
		}
		k++;
	}
	cout << cnt << '\n';
}