#include <iostream>
#include <vector>
using namespace std;

vector<int> graph[100];
bool visited[100];

void init() 
{
	for (int i = 0; i < 100; i++) {
		visited[i] = false;
		graph[i].clear();
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

int main(int argc, char** argv)
{
	int n, T = 10;
	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case >> n;

		init();

		int u, v;
		for (int i = 0; i < n; i++) {
			cin >> u >> v;
			graph[u].push_back(v);
		}

		dfs(0);

		cout << "#" << test_case << " ";
		if (visited[99]) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}