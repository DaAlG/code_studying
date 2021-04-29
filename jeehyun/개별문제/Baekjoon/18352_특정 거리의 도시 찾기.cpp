/*
 * 그래프
 * 18352 특정 거리의 도시 찾기
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 300001
#define INF 0x3f3f3f
using namespace std;

vector<int> graph[MAX];
int d[MAX];

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
			int next = graph[cur][i];
			int nextDist = dist + 1;
	
			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist , next });
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k, start;
	cin >> n >> m >> k >> start;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	fill(d, d + MAX, INF);

	dijkstra(start);

	int answer = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] == k) {
			cout << i << '\n';
			answer++;
		}
	}

	if (answer == 0)
		cout << -1;

	return 0;
}