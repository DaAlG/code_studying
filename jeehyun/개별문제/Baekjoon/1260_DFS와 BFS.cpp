/* 그래프
 * 1260 DFS와 BFS
 * 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과 출력
 * 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고,
 * 더 이상 방문할 수 있는 점이 없는 경우 종료한다
 * 정점 번호는 1번부터 N번까지이다
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector<vector<int>> graph;
bool *visited;

void dfs(int v)
{
	cout << v << " ";
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++)
		if (!visited[graph[v][i]])
			dfs(graph[v][i]);
}

void bfs(int v)
{
	queue<int> q;
	q.push(v);
	visited[v] = true;
	
	while (!q.empty()) {
		int n = q.front();
		q.pop();
		cout << n << " ";

		for (int i = 0; i < graph[n].size(); i++) {
			int next = graph[n][i];
			if (!visited[next]) {
				q.push(next);
				visited[next] = true;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, start;
	cin >> n >> m >> start;

	int u, v;
	graph = vector<vector<int>>(n + 1, vector<int>());
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end());

	visited = new bool[n + 1];
	memset(visited, false, n + 1);
	dfs(start);
	cout << "\n";
	memset(visited, false, n + 1);
	bfs(start);

	return 0;
}