/*
 * 그래프
 * 16202 MST 게임
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1001
using namespace std;

int set[MAX];

struct Edge {
	int x; // 정점 x
	int y; // 정점 y
	int c; // 비용
};

int getParent(int x)
{
	if (set[x] == x) return x;
	else return set[x] = getParent(set[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

bool cmp(Edge a, Edge b)
{
	return a.c < b.c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m >> k;

	vector<Edge> edges(m);
	for (int i = 0; i < m; i++) {
		cin >> edges[i].x >> edges[i].y;
		edges[i].c = i + 1;
	}
	sort(edges.begin(), edges.end(), cmp);

	bool impossible = false;
	while (k--) {
		// 어떤 턴에서 MST를 만들 수 없다면 그 이후 모든 턴의 점수도 0
		if (impossible) {
			cout << 0 << ' ';
			continue;
		}

		for (int i = 1; i <= n; i++) {
			set[i] = i;
		}

		int answer = 0;
		int cnt = 1;
		int minEdge = 0;

		for (int i = 0; i < edges.size(); i++) {
			if (!findParent(edges[i].x, edges[i].y)) {
				if (cnt == 1)
					minEdge = i;
				cnt++;
				answer += edges[i].c;
				unionParent(edges[i].x, edges[i].y);
			}
		}

		// MST를 만들 수 없을 경우 점수는 0
		if (cnt < n) {
			cout << 0 << ' ';
			impossible = true;
			continue;
		}

		cout << answer << ' ';

		// MST에서 가장 가중치가 작은 간선 하나 제거
		edges.erase(edges.begin() + minEdge);
	}

	return 0;
}