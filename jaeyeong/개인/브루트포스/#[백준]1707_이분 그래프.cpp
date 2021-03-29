using namespace std;
#include <iostream>
#include <vector>
#include <cstring>
#define RED 1
#define BLUE 2

int v, e;
int visit[20001], colors[20001];
vector<int> graph[20001];

void dfs(int idx) {
	if (visit[idx] == 0) {
		visit[idx] = RED;
	}

	int size = graph[idx].size();
	for (int i = 0; i < size; i++) {
		int next = graph[idx][i];
		if (visit[next] == 0) {
			if (visit[idx] == RED) {
				visit[next] = BLUE;
			}
			else if (visit[idx] == BLUE) {
				visit[next] = RED;
			}
			dfs(next);
		}
	}
}

bool isBipartite() {
	for (int i = 1; i <= v; i++) {
		int size = graph[i].size();
		for (int j = 0; j < size; j++) {
			int next = graph[i][j];
			if (visit[i] == visit[next])
				return false;
		}
	}
	return true;
}
int main() {
	int test, x, y;
	cin >> test;
	while (test--) {
		cin >> v >> e;

		for (int i = 0; i < e; i++) {
			cin >> x >> y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		
		for (int i = 1; i <= v; i++) {
			if (visit[i] == 0)
				dfs(i);
		}
		if (isBipartite() == true) cout << "YES" << '\n';
		else cout << "NO" << '\n';

		for (int i = 0; i <= v; i++)
			graph[i].clear();
		memset(visit, false, sizeof(visit));
	}
}