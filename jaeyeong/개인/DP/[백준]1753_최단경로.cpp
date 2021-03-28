using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

int v, e, s;
vector<pair<int, int>> graph[20001];

vector<int> dijkstra() {
	priority_queue<pair<int,int>> pq;
	vector<int> d(v+1, INF);

	d[s] = 0;
	pq.push(make_pair(0, s));
	while (!pq.empty()) {
		int distance = -pq.top().first;
		int node = pq.top().second;
		pq.pop();
		if (d[node] < distance) continue;
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i].second;
			int nextDistance = distance + graph[node][i].first;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	return d;
}
int main() {
	int x, y, z;

	cin >> v >> e;
	cin >> s;
	for (int i = 1; i <= e; i++) {
		cin >> x >> y >> z;
		graph[x].push_back(make_pair(z, y));
	}

	vector<int> d = dijkstra();
	for (int i = 1; i <= v; i++) {
		if (d[i] == INF) cout << "INF" << '\n';
		else cout << d[i] << '\n';
	}
}