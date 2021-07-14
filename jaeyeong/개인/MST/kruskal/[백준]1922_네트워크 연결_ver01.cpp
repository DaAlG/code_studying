using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define MAX 1001
//MST 문제. Kruskal 버전
typedef tuple<int,int,int> node;

int n, m;
priority_queue<node> edge;
bool visit[MAX];
int ans;
int p[MAX];

int getParent(int x) {
	if (p[x] == x) return x;
	return p[x] = getParent(p[x]);
}

void unionParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	if (x < y) p[y] = x;
	else p[x] = y;
}

bool sameParent(int x, int y) {
	x = getParent(x);
	y = getParent(y);
	return x == y;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	int a, b, c;
	for(int i=0;i<m;i++) {
		cin >> a >> b >> c;
		edge.push(make_tuple(-c, a, b));
		// c의비용, a에서 b로 갈 수 있다.
	}
	for (int i = 1; i <= n; i++)
		p[i] = i;

	node k;
	int cost, x, y;
	while (!edge.empty()) {
		do {
			k = edge.top();
			tie(cost, x, y) = k;
			edge.pop();
		} while (sameParent(x,y) && !edge.empty());
		if (sameParent(x, y) && edge.empty()) break;
		unionParent(x, y);
		ans -= cost;
	}
	cout << ans << '\n';
}