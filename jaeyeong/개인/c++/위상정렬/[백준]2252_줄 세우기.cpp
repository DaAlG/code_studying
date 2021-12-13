using namespace std;
#include <iostream>
#include <queue>
#include <vector>
#define MAX 32001
//위상정렬(Topological Sort)
//일반적으로 위상정렬의 결과는 유일하지 않다

int n, m;
int in[MAX];
vector<int> t[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	int a, b;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		t[a].push_back(b);
		in[b]++;
	}

	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (in[i] == 0) q.push(i);

	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int node : t[v]) {
			if ((in[node] -= 1) == 0) {
				q.push(node);
			}
		}
		cout << v << ' ';
	}
}