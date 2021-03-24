using namespace std;
#include <iostream>
#include <vector>
#include <queue>

int n, k;
vector<int> graph[101];
int visit[101];
void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start] = 1;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			int nextNode = graph[v][i];
			if (visit[nextNode] == 0) {
				q.push(nextNode);
				visit[nextNode] = 1;
			}
		}
	}

}
int main() {
	int x, y, answer=0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
		if (visit[i] == 1) answer++;
	cout << answer << '\n';

}