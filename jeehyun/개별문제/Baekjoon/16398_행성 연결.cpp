/*
 * 그래프
 * 16398 행성 연결
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int set[1001];

struct Flow {
	int u;
	int v;
	int c;
};

bool cmp(Flow a, Flow b)
{
	return a.c < b.c;
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

	int n, cost;
	cin >> n;

	vector<Flow> flows;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> cost;
			if (i != j) {
				flows.push_back({ i, j, cost });
			}
		}
	}
	sort(flows.begin(), flows.end(), cmp);

	for (int i = 1; i <= n; i++) set[i] = i;

	long long answer = 0;
	for (int i = 0; i < flows.size(); i++) {
		if (!findParent(flows[i].u, flows[i].v)) {
			answer += flows[i].c;
			unionParent(flows[i].u, flows[i].v);
		}
	}
	cout << answer;

	return 0;
}