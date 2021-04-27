/*
 * DFS
 * 2606 바이러스
 */

#include <iostream>
#include <vector>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
bool visited[MAX];
int answer = 0;

void dfs(int x)
{
	if (visited[x]) return;

	visited[x] = true;
	answer++;

	for (int y : graph[x]) {
		if (!visited[y]) {
			dfs(y);
		}
	}
}

int main()
{
	int n, e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	dfs(1);
	answer--;

	cout << answer;
	return 0;
}