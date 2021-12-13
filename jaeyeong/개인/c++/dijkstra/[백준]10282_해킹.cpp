using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 10001
#define INF 0x3f3f3f3f
int dist[MAX];

void dijkstra(int start, vector<vector<pair<int, int>>> graph) {
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push(make_pair(0, start));
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (dist[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++) {
			int nextDistance = distance + graph[current][i].second;
			int next = graph[current][i].first;
			if (nextDistance < dist[next]) {
				dist[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int tc;
	cin >> tc;
	while (tc--) {
		//컴퓨터 개수 n, 의존성 개수 d, 해킹당한 컴퓨터 번호 d
		int n, d, c;
		cin >> n >> d >> c;
		memset(dist, INF, sizeof(dist));
		vector<vector<pair<int, int>>> graph(n+1);
		for (int i = 0; i < d; i++) {
			int a, b, s;
			cin >> a >> b >> s;
			graph[b].push_back({ a,s });
		}
		dijkstra(c, graph);
		int cnt = 0, mx = 0;
		for (int i = 1; i <= n; i++) {
			if (dist[i] != INF) {
				cnt++;
				mx = max(mx, dist[i]);
			}
		}
		cout << cnt << ' ' << mx << '\n';
	}
}