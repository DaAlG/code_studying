/*
 * 그래프
 * 2252 줄 세우기
 */

#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int n, m;
vector<int> graph[MAX];
int cnt[MAX]; // 선행 정점 개수

void topologicalSort()
{
	queue<int> q;

	// 선행 정점을 가지지 않는 정점을 큐에 삽입
	for (int i = 1; i <= n; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}

	// 정점의 수만큼 반복
	for (int i = 0; i < n; i++) {
		int v = q.front();
		q.pop();

		cout << v << ' ';

		for (int j = 0; j < graph[v].size(); j++) {
			int next = graph[v][j];
			
			// 간선 수 감소
			cnt[next]--;

			// 선행 정점을 가지지 않는 정점을 큐에 삽입
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

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		cnt[v]++; // 후행 정점에 대한 간선의 수 증가
	}

	// 위상 정렬 (A B : A가 B 앞에 선다. A가 선행)
	topologicalSort();

	return 0;
}