#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define MAX 1001
#define INF 987654321
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

int n, m;
vector<pii> graph[MAX];
int d[MAX];
int dp[MAX];

void dijkstra(int start)
{
	fill_n(d, MAX, INF);
	priority_queue<pii> pq;
	pq.push({ 0, start });

	d[start] = 0;
	dp[start] = 1;

	while (!pq.empty()) {
		int cur = pq.top().se;
		int dist = -pq.top().fi;
		pq.pop();

		if (d[cur] < dist) 
			continue;

		for (auto node : graph[cur]) {
			int next = node.fi;
			int nextDist = node.se + dist;

			if (nextDist < d[next]) {
				d[next] = nextDist;
				pq.push({ -nextDist, next });
			}

			if (d[next] < dist) // 합리적인 이동 경로 존재
				dp[cur] += dp[next];
		}
	}
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
		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });
	}

	dijkstra(2);
	cout << dp[1];
	return 0;
}