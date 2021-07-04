/*
 * 그래프
 * 6497 전력난
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200000
using namespace std;

int set[MAX];

struct Road {
	int x; // x번 집
	int y; // y번 집
	int z; // z 거리
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

bool cmp(Road a, Road b)
{
	return a.z < b.z;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int m, n;
	while (cin >> m >> n) {
		if (m == 0 && n == 0)
			break;

		for (int i = 0; i < m; i++) {
			set[i] = i;
		}

		vector<Road> roads(n);
		int answer = 0;

		for (int i = 0; i < n; i++) {
			cin >> roads[i].x >> roads[i].y >> roads[i].z;
			answer += roads[i].z;
		}
		sort(roads.begin(), roads.end(), cmp);

		for (int i = 0; i < n; i++) {
			if (!findParent(roads[i].x, roads[i].y)) {
				answer -= roads[i].z;
				unionParent(roads[i].x, roads[i].y);
			}
		}
		cout << answer << '\n';
	}
	
	return 0;
}