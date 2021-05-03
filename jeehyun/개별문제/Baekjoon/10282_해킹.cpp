/*
 * 그래프
 * 10282 해킹
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 10001
#define INF 0x7fffffff
using namespace std;

vector<pair<int, int>> *graph;
int d[MAX];
int answer;

int dijkstra(int n, int start)
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

	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (d[i] != INF) {
			answer++;
			// 마지막 컴퓨터가 감염되기까지 걸리는 시간은 최댓값을 찾으면 된다
			last = max(last, d[i]);
		}
	}

	return last;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, D, c;
		cin >> n >> D >> c;

		fill(d, d + MAX, INF);
		graph = new vector<pair<int, int>>[n + 1];

		for (int i = 0; i < D; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a, s });
		}

		answer = 0;
		int totalTime = dijkstra(n, c);

		cout << answer << ' ' << totalTime << '\n';
	}

	return 0;
}