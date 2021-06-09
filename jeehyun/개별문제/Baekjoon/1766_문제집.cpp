/*
 * 그래프
 * 1766 문제집
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int n, m;
int cnt[MAX];
vector<int> graph[MAX];

void topologicalSort()
{
	// 1 ~ N순으로 점점 어려워진다
	// 쉬운 문제부터 풀어야 하므로 우선순위 큐는 오름차순으로 정렬
	priority_queue<int, vector<int>, greater<int>> pq;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			pq.push(i);
	}

	for (int i = 0; i < n; i++) {
		int v = pq.top();
		pq.pop();

		cout << v << ' ';

		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];
			cnt[next]--;

			if (cnt[next] == 0)
				pq.push(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	while (m--) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		cnt[v]++;
	}

	topologicalSort();
	return 0;
}