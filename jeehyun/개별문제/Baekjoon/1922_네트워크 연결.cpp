/*
 * 그래프
 * 1922 네트워크 연결
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int set[1001];

struct Line {
	int u;
	int v;
	int c;
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

bool cmp(Line a, Line b)
{
	return a.c < b.c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<Line> lines(m);
	for (int i = 0; i < m; i++) {
		cin >> lines[i].u >> lines[i].v >> lines[i].c;
	}
	sort(lines.begin(), lines.end(), cmp);

	for (int i = 1; i <= n; i++) {
		set[i] = i;
	}

	int answer = 0;
	for (int i = 0; i < lines.size(); i++) {
		if (!findParent(lines[i].u, lines[i].v)) {
			answer += lines[i].c;
			unionParent(lines[i].u, lines[i].v);
		}
	}
	cout << answer;
	return 0;
}