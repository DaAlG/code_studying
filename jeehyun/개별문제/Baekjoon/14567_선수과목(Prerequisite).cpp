#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int n, m;
vector<int> graph[MAX];
int cnt[MAX];
int answer[MAX];

void topologicalSort() 
{
	queue<pair<int, int>> q;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			q.push({ i, 1 });
		}
	}

	while (!q.empty()) {
		int cur = q.front().first;
		int seme = q.front().second;
		q.pop();

		answer[cur] = seme;

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];

			cnt[next]--;

			if (cnt[next] == 0) {
				q.push({ next, seme + 1 });
			}
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
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		cnt[v]++;
	}

	topologicalSort();

	for (int i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}

	return 0;
}