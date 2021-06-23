/* 
 * 그래프
 * 1414 불우이웃돕기
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int set[101];

struct Edge {
	int u;
	int v;
	int w;
};

int length(char ch) 
{
	if (ch == '0')
		return 0;
	if (ch >= 'a' && ch <= 'z')
		return ch - 'a' + 1;
	else // A ~ Z
		return ch - 'A' + 27;
}

bool cmp(Edge a, Edge b)
{
	return a.w < b.w;
}

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

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	char ch;
	int answer = 0;
	vector<Edge> edges;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> ch;
			int len = length(ch);
			if (len != 0) {
				edges.push_back({ i, j, len });
				answer += edges.back().w;
			}
		}
	}
	sort(edges.begin(), edges.end(), cmp);


	for (int i = 1; i <= n; i++) set[i] = i;

	int cnt = 1;
	for (int i = 0; i < edges.size(); i++) {
		if (!findParent(edges[i].u, edges[i].v)) {
			cnt++;
			answer -= edges[i].w;
			unionParent(edges[i].u, edges[i].v);
		}
	}

	if (cnt < n) cout << -1;
	else cout << answer;

	return 0;
}