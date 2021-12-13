using namespace std;
#include <iostream>
#include <vector>
#include <queue>

int n;
vector<int> graph[100001];
int visit[100001];

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = 0;
	while (!q.empty()) {
		int c = q.front();
		q.pop();
		for (int i = 0; i < graph[c].size(); i++) {
			int nextNode = graph[c][i];
			if (visit[nextNode] == 0) {
				visit[nextNode] = c;
				q.push(nextNode);
			}
		}
	}
}
int main() {
	int x, y;
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	bfs();
	for (int i = 2; i <= n; i++)
		cout << visit[i] << '\n';
}