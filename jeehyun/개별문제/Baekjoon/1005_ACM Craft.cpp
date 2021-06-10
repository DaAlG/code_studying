/*
 * 그래프
 * 1005 ACM Craft
 */

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;

int n, k, w;
int t[MAX]; // 건설시간
int cnt[MAX]; // 선행 정점 개수
int dp[MAX]; // 최소 건설시간
vector<int> graph[MAX];

void init() {
	memset(cnt, 0, sizeof(cnt));
	memset(t, 0, sizeof(t));
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < MAX; i++)
		graph[i].clear();
}

void topologicalSort()
{
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0) {
			dp[i] = t[i];
			q.push(i);
		}
	}

	for (int i = 0; i < n; i++) {
		int v = q.front();
		q.pop();

		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];

			cnt[next]--;

			// 건물을 짓기 위해 걸리는 최소시간
			// 앞순서 건물들이 모두 건설 완료되어야지만 건설을 시작할 수 있으므로 최댓값을 찾는다
			dp[next] = max(dp[next], dp[v] + t[next]);

			if (cnt[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		cin >> n >> k;

		init();
		for (int i = 1; i <= n; i++) {
			cin >> t[i];
		}

		while (k--) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			cnt[v]++;
		}

		cin >> w;

		topologicalSort();
		cout << dp[w] << '\n';
	}

	return 0;
}