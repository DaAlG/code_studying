using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#define INF 0x3f3f3f3f
#define MAX 1001

int d[MAX], parent[MAX];
vector<pair<int, int>> bus[MAX]; //(도착도시, 비용)

void dijkstra(int start, int dest) {
	priority_queue<pair<int,int>> q; // (-비용, 도시)
	q.push(make_pair(0,start));
	d[start] = 0;
	while (!q.empty()) {
		int cost = -q.top().first;
		int city = q.top().second;
		q.pop();
		if (cost > d[city]) continue;
		for (int i = 0; i < bus[city].size(); i++) {
			int nextCost = bus[city][i].second + cost;
			int nextCity = bus[city][i].first;
			if (d[nextCity] > nextCost) {
				parent[nextCity] = city;
				d[nextCity] = nextCost;
				q.push(make_pair(-nextCost, nextCity));
			}
		}
	}

	cout << d[dest] << '\n';
	stack<int> ans;
	int next = dest;
	int cnt = 1;
	ans.push(dest);
	while (next != start) {
		ans.push(parent[next]);
		next = parent[next];
		cnt++;
	}
	cout << cnt << '\n';
	while (!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop();
	}
	return;
}
int main() {
	int n, m;
	int a, b, c;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		bus[a].push_back(make_pair(b, c));
	}
	int start, dest;
	cin >> start >> dest;
	for (int i = 1; i <= n; i++) {
		d[i] = INF;
		parent[i] = start;
	}
	dijkstra(start, dest);
}