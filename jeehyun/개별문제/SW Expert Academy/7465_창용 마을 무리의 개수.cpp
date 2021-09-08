#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

int n, m;
vector<int> graph[MAX];
bool visited[MAX];

void init()
{
	for (int i = 1; i <= n; i++) {
		graph[i].clear();
		visited[i] = false;
	}
}

void dfs(int v)
{
	visited[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n >> m;
		init();

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int answer = 0;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				answer++;
				dfs(i);
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}