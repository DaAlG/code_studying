/*
 * 그래프
 * 1238 파티
 * Dijkstra
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define INF 0x3f3f3f
using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];
int res[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		if (d[cur] < dist)
			continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].first;
			int nextDist = dist + graph[cur][i].second;

			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, x;
	cin >> n >> m >> x;	

	for (int i = 0; i < m; i++) {
		int u, v, t;
		cin >> u >> v >> t;
		graph[u].push_back({ v, t });
	}

	// 각 마을에서 x로 가는데 걸리는 시간을 구한다
	fill(d, d + MAX, INF);
	dijkstra(x);
	for (int i = 1; i <= n; i++) res[i] = d[i];

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		// x에서 i번째 마을로 돌아오는 시간을 구한다
		fill(d, d + MAX, INF);
		dijkstra(i);

		res[i] += d[x];
		answer = max(answer, res[i]);
	}
	cout << answer;

	return 0;
}