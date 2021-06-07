/*
 * 그래프
 * 1197 최소 스패닝 트리
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
using namespace std;

int set[MAX];

struct Edge {
	int u;
	int v;
	int c;
};

bool cmp(Edge a, Edge b)
{
	return a.c < b.c;
}

// 부모 노드를 가져온다
int getParent(int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set[x]);
}

// 부모 노드를 병합
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);

	// 더 숫자가 작은 부모로 병합
	if (a < b) set[b] = a;
	else set[a] = b;
}

// 같은 부모를 가지는지 확인
int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int v, e;
	cin >> v >> e;

	vector<Edge> edge(e);
	for (int i = 0; i < e; i++) {
		cin >> edge[i].u >> edge[i].v >> edge[i].c;
	}

	// 간선의 비용으로 오름차순 정렬
	sort(edge.begin(), edge.end(), cmp);

	// 각 정점이 포함된 그래프가 어디인지 저장
	for (int i = 1; i <= v; i++) {
		set[i] = i;
	}
	
	int answer = 0;

	for (int i = 0; i < e; i++) {
		// 동일한 부모를 가르키지 않는 경우, 즉 사이클이 발생하지 않을 때만 선택
		if (!find(edge[i].u, edge[i].v)) {
			answer += edge[i].c;
			unionParent(edge[i].u, edge[i].v);
		}
	}
	cout << answer;

	return 0;
}