using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001

int n, m;
vector<pair<int, int>> graph[MAX];
int d[MAX];

void dijkstra(int start, int dest) {
	d[start] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(start, 0));
	//가까운 순서대로 처리
	while (!pq.empty()) {
		int current = pq.top().first;
		int distance = -pq.top().second;
		pq.pop();
		if (d[current] < distance) continue;
		for (int i = 0; i < graph[current].size(); i++) {
			int next = graph[current][i].first;
			int nextDistance = distance + graph[current][i].second;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(next, -nextDistance));
			}
		}
	}
	cout << d[dest] << '\n';
	return;
}
int main() {
	int x, y, z;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		d[i] = 0x3f3f3f3f;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		graph[x].push_back(make_pair(y, z));
	}
	cin >> x >> y;
	dijkstra(x, y);
	return 0;
}