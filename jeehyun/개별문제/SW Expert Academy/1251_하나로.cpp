#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000
using namespace std;

typedef long long ll;

int n;
double e;
vector<pair<ll, ll>> island;
int set[MAX];

struct Tunnel {
	int a, b;
	ll dist;
	Tunnel(int a, int b, ll dist) : a(a), b(b), dist(dist) {}
};

bool cmp(Tunnel a, Tunnel b)
{
	return a.dist < b.dist;
}

ll getDist(int a, int b)
{
	ll dist = (island[a].first - island[b].first) * (island[a].first - island[b].first);
	dist += (island[a].second - island[b].second) * (island[a].second - island[b].second);
	return dist;
}

int getParent(int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int find(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int x, y;
		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> x;
			island.push_back({ x, 0 });
			set[i] = i;
		}
		for (int i = 0; i < n; i++) cin >> island[i].second;
		cin >> e;

		vector<Tunnel> tunnels;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				tunnels.push_back(Tunnel(i, j, getDist(i, j)));
			}
		}
		sort(tunnels.begin(), tunnels.end(), cmp);


		ll answer = 0;
		for (int i = 0; i < tunnels.size(); i++) {
			if (!find(tunnels[i].a, tunnels[i].b)) {
				answer += tunnels[i].dist;
				unionParent(tunnels[i].a, tunnels[i].b);
			}
		}
		answer = round(answer * e);

		cout << "#" << test_case << " " << answer << "\n";
		island.clear();
	}
	return 0;
}