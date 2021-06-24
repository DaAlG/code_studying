/*
 * 그래프
 * 2665 미로만들기
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int set[100001];

struct Street {
	int a;
	int b;
	int c;
};

bool cmp(Street a, Street b)
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

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) set[i] = i;

	vector<Street> streets(m);
	for (int i = 0; i < m; i++) {
		cin >> streets[i].a >> streets[i].b >> streets[i].c;
	}
	sort(streets.begin(), streets.end(), cmp);

	int answer = 0;
	int cnt = 1;

	for (int i = 0; i < m; i++) {
		if (cnt < n - 1 && !findParent(streets[i].a, streets[i].b)) {
			cnt++;
			answer += streets[i].c;
			unionParent(streets[i].a, streets[i].b);
		}
	}
	cout << answer;
	return 0;
}