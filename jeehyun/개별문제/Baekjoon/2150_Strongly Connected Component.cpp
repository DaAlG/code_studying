/*
 * 그래프
 * 2150 Strongly Connected Component
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#define MAX 10001
using namespace std;

int n, e;
int id, d[MAX];
bool finished[MAX];
vector<int> graph[MAX];
vector<vector<int>> SCC;
stack<int> s;

int dfs(int x)
{
	d[x] = ++id; // 노드마다 고유번호 할당
	s.push(x); // 스택에 자기 자신 삽입

	int parent = d[x];
	for (int i = 0; i < graph[x].size(); i++) {
		int next = graph[x][i];

		if (d[next] == 0) parent = min(parent, dfs(next)); // 방문하지 않은 이웃
		else if (!finished[next]) parent = min(parent, d[next]); // 처리 중인 이웃
	}

	if (parent == d[x]) { // 부모 노드가 자기 자신인 경우
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		sort(scc.begin(), scc.end());
		SCC.push_back(scc);
	}

	// 자신의 부모 반환
	return parent;
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> e;
	for (int i = 0; i < e; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
	}

	for (int i = 1; i <= n; i++) {
		if (d[i] == 0) dfs(i);
	}
	sort(SCC.begin(), SCC.end());

	cout << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		for (int j = 0; j < SCC[i].size(); j++) {
			cout << SCC[i][j] << ' ';
		}
		cout << -1 << '\n';
	}

	return 0;
}