#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define INF LLONG_MAX
#define MAX 501
#define endl "\n"
using namespace std;

struct Edge {
	int from, to, cost;
	Edge(int from, int to, int cost) : from(from), to(to), cost(cost) { }
};

int n, m;
vector<Edge> bus;
long long d[MAX];

bool bellmanFord(int start)
{
	d[start] = 0;
	
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 0; j < bus.size(); j++) {
			int from = bus[j].from;
			int to = bus[j].to;
			int cost = bus[j].cost;

			if (d[from] == INF) continue;

			// 최소비용 갱신
			if (d[to] > d[from] + cost) d[to] = d[from] + cost;
		}
	}

	for (int i = 0; i < bus.size(); i++) {
		int from = bus[i].from;
		int to = bus[i].to;
		int cost = bus[i].cost;

		if (d[from] == INF) continue;

		// 음의 사이클이 존재 -> 시간을 무한히 오래 전으로 되돌릴 수 있는 경우
		if (d[to] > d[from] + cost) return false;
	}

	return true;
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		bus.push_back(Edge(a, b, c));
	}

	fill_n(d, MAX, INF);
	
	if (bellmanFord(1)) {
		for (int i = 2; i <= n; i++) {
			if (d[i] == INF) cout << -1 << endl;
			else cout << d[i] << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
	return 0;
}