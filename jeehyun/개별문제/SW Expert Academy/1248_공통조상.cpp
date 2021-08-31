#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 10001
#define LOG 14 // 전체 노드의 개수가 2^14 이하
using namespace std;

int n, m; // 정점 총 수, 간선 총 수
int parent[MAX][LOG]; // 부모 관계
int d[MAX]; // depth
vector<int> tree[MAX];
int cnt[MAX]; // 서브트리 크기

void init() 
{
	for (int i = 1; i <= n; i++) {
		d[i] = 0;
		cnt[i] = false;
		tree[i].clear();
		fill_n(parent[i], LOG, 0);
	}
}

void dfs(int x, int depth) 
{
	cnt[x] = 1;
	d[x] = depth;
	for (int i = 0; i < tree[x].size(); i++) {
		int y = tree[x][i];
		if (cnt[y] > 0) continue;
		parent[y][0] = x;
		dfs(y, depth + 1);
		cnt[x] += cnt[y];
	}
}

void setParent() 
{
	dfs(1, 0);
	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

int LCA(int x, int y)
{
	if (d[x] > d[y]) {
		swap(x, y);
	}

	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	if (x == y) return x;

	for (int i = LOG - 1; i >= 0; i--) {
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}

	return parent[x][0];
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int a, b, u, v;
		cin >> n >> m >> a >> b;

		init();

		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			tree[u].push_back(v);
			tree[v].push_back(u);
		}

		setParent();
		int answer = LCA(a, b);

		cout << "#" << test_case << " " << answer << " " << cnt[answer] << "\n";
	}

	return 0;
}