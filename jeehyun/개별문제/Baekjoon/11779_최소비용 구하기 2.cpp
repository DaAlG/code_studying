/*
 * 그래프
 * 11779 최소비용 구하기 2
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
#define INF 0x7fffffff
using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];
int rec[MAX];

void dijkstra(int start, int dest)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < dist)
			continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = dist + graph[cur][i].second;

			if (nextDist < d[next]) {
				d[next] = nextDist;
				rec[next] = cur;
				pq.push({ nextDist, next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	fill(d, d + MAX, INF);

	int start, dest;
	cin >> start >> dest;

	dijkstra(start, dest);

	vector<int> path;
	path.push_back(dest);
	for (int p = rec[dest]; p != 0; p = rec[p]) {
		path.push_back(p);
	}
	reverse(path.begin(), path.end());

	cout << d[dest] << '\n';
	cout << path.size() << '\n';
	for (int k : path) {
		cout << k << ' ';
	}

	return 0;
}