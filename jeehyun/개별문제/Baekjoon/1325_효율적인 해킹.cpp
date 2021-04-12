/*
 * 그래프
 * 1325 효율적인 해킹
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

vector<int> graph[MAX];
int arr[MAX];
bool visited[MAX];

int dfs(int v, int cnt)
{
	visited[v] = true;

	for (int i = 0; i < graph[v].size(); i++) {
		if (!visited[graph[v][i]]) {
			cnt = dfs(graph[v][i], cnt + 1);
		}
	}
	
	return cnt;
}

int main()
{
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[v].push_back(u);
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		fill(visited, visited + MAX, false);
		// 해킹할 수 있는 컴퓨터의 개수를 구한다
		arr[i] = dfs(i, 1);
		cnt = max(cnt, arr[i]);
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == cnt) // 가장 많은 컴퓨터를 해킹할 수 있다면 번호 출력
			cout << i << ' ';
	}

	return 0;
}