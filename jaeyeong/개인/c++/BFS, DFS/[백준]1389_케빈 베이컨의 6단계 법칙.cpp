using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 101

vector<int> graph[MAX];
int visit[MAX];
int bacon[MAX];
int n, m;

void bfs() {
	int answer = 1;
	for (int i = 1; i <= n; i++) {
		queue<int> q;
		q.push(i);
		visit[i] = 1;
		while (!q.empty()) {
			int c = q.front();
			q.pop();
			for (int i = 0; i < graph[c].size(); i++) {
				int next = graph[c][i];
				if (!visit[next]) {
					visit[next] = visit[c] + 1;
					q.push(next);
				}
			}
		}
		for (int j = 1; j <= n; j++)
			bacon[i] += visit[j] - 1;
		memset(visit, 0, sizeof(visit));
	}

	for (int i = 1; i <= n; i++)
		answer = bacon[i] < bacon[answer] ? i : answer;

	cout << answer << '\n';
}
int main() {
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		graph[i].erase(unique(graph[i].begin(), graph[i].end()), graph[i].end());
	}
	bfs();
}