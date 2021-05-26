/*
 * 그래프
 * 9372 상근이의 여행
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int n, m;
int answer;
vector<int>* graph;
bool visited[MAX];

void dfs(int v)
{
	if (visited[v]) return;

	answer++;
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n >> m;

		graph = new vector<int>[n + 1];

		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		fill_n(visited, MAX, false);
		answer = 0;

		dfs(1);

		cout << answer - 1 << '\n';
	}

	return 0;
}