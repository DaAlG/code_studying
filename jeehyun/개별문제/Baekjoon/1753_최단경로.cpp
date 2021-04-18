/*
 * 그래프
 * 1753 최단경로
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 20001
#define INF 0x3f3f3f
using namespace std;

vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start)
{
	priority_queue<pair<int, int>> pq; // 거리, 노드
	pq.push({ 0, start });
	d[start] = 0;

	while (!pq.empty()) {
		// 현재 노드까지의 거리
		int dist = -pq.top().first;
		// 현재 노드
		int cur = pq.top().second;
		pq.pop();

		// 최단 거리가 아닌 경우 스킵
		if (d[cur] < dist) continue;

		for (int i = 0; i < graph[cur].size(); i++) {
			// 선택된 노드의 인접 노드
			int next = graph[cur][i].first;
			// 선택된 노드를 거쳐서 가는 비용
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
	int v, e, k; // 정점 개수, 간선 개수, 시작 정점
	cin >> v >> e >> k;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back({ b, c });
	}

	fill(d, d + MAX, INF);
	dijkstra(k);

	for (int i = 1; i <= v; i++) {
		if (d[i] == INF)
			cout << "INF\n";
		else
			cout << d[i] << '\n';
	}

	return 0;
}