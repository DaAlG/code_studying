/*
 * 그래프
 * 2623 음악프로그램
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int n, m;
int cnt[MAX];
vector<int> graph[MAX];
vector<int> answer;

void topologicalSort()
{
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty())
			break;

		int v = q.front();
		q.pop();

		answer.push_back(v);

		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];
			cnt[next]--;

			if (cnt[next] == 0)
				q.push(next);
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
		int k, u, v;
		cin >> k >> u;
		for (int i = 1; i < k; i++) {
			cin >> v;
			graph[u].push_back(v);
			cnt[v]++;
			u = v;
		}
	}

	topologicalSort();

	if (answer.size() == n) {
		for (int k : answer) {
			cout << k << '\n';
		}
	}
	else {
		cout << 0;
	}

	return 0;
}