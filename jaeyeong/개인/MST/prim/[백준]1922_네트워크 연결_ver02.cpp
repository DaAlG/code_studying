using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 1001
//프림 알고리즘
typedef pair<int, int> node;

int n, m;
vector<node> graph[MAX];
bool visit[MAX];
int ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	int a, b, c;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(-c, b));
		graph[b].push_back(make_pair(-c, a));
		// c의비용, a에서 b로 갈 수 있다.
	}
	priority_queue<pair<int, int>> q;
	q.push(make_pair(0, 1));
	int cnt = 0;
	while (!q.empty()) {
		int cost = q.top().first;
		int curNode = q.top().second;
		q.pop();
		if (visit[curNode]) continue;
		visit[curNode] = true;
		ans += cost;
		if (++cnt == n) break;
		for (pair<int, int> next : graph[curNode]) {
			if (!visit[next.second])
				q.push(next);
		}
	}
	cout << -ans << '\n';
}