/*
 * 그래프
 * 20010 악덕 영주 혜유
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1001
using namespace std;

int set[MAX];
vector<pair<int, int>> graph[MAX];
bool visited[MAX];
int maxCost;

struct Edge {
	int x; // 정점 x
	int y; // 정점 y
	int c; // 비용
};

int getParent(int x)
{
	if (set[x] == x) return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

bool cmp(Edge a, Edge b)
{
	return a.c < b.c;
}

void dfs(int v, int c)
{
	if (visited[v]) return;

	visited[v] = true;
	maxCost = max(maxCost, c);

	for (int i = 0; i < graph[v].size(); i++) {
		dfs(graph[v][i].first, c + graph[v][i].second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<Edge> edges(k);
	for (int i = 0; i < k; i++) {
		cin >> edges[i].x >> edges[i].y >> edges[i].c;
	}
	sort(edges.begin(), edges.end(), cmp);

	
	for (int i = 0; i < n; i++) set[i] = i;

	int answer = 0; // 최소비용

	for (int i = 0; i < edges.size(); i++) {
		if (!findParent(edges[i].x, edges[i].y)) {
			answer += edges[i].c;
			unionParent(edges[i].x, edges[i].y);
			graph[edges[i].x].push_back({ edges[i].y, edges[i].c });
			graph[edges[i].y].push_back({ edges[i].x, edges[i].c });
		}
	}
	cout << answer << '\n';

	for (int i = 0; i < n; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i, 0);
	}
	cout << maxCost;
	return 0;
}