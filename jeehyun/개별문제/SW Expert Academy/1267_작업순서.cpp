#include<iostream>
#include <vector>
#include <queue>
#define MAX 1001
using namespace std;

int v, e;
vector<int> graph[MAX];
int cnt[MAX]; // 선행 정점 개수

void init() {
	for (int i = 1; i <= v; i++) {
		graph[i].clear();
		cnt[i] = 0;
	}
}

void topologicalSort() {
	queue<int> q;

	// 선행 정점을 가지지 않는 정점을 큐에 삽입
	for (int i = 1; i <= v; i++) {
		if (cnt[i] == 0)
			q.push(i);
	}

	for (int i = 0; i < v; i++) {
		int cur = q.front();
		q.pop();

		cout << cur << " ";

		for (int j = 0; j < graph[cur].size(); j++) {
			int next = graph[cur][j];

			// 간선 수 감소
			cnt[next]--;

			// 선행 정점을 가지지 않는 정점을 큐에 삽입
			if (cnt[next] == 0) {
				q.push(next);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int T = 10;

	for (int test_case = 1; test_case <= T; ++test_case) {
		cin >> v >> e;

		init();

		int a, b;
		for (int i = 0; i < e; i++) {
			cin >> a >> b;
			graph[a].push_back(b);
			cnt[b]++; // 후행 정점에 대한 간선의 수 증가
		}

		cout << "#" << test_case << " ";
		topologicalSort();
		cout << "\n";
	}
	return 0;
}