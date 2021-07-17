/*
 * 그래프
 * 11437 LCA
 */

#include <iostream>
#include <vector>
#define MAX 50001
#define LOG 16 // 전체 노드의 갯수는 2^16개 이하
using namespace std;

int n, m;
int parent[MAX][LOG], d[MAX]; // 부모 관계, depth
bool visited[MAX]; // 방문 여부 체크
vector<int> tree[MAX]; // 트리

// 바로 윗 부모와 연결
void dfs(int x, int depth) 
{
	visited[x] = true;
	d[x] = depth;

	for (int i = 0; i < tree[x].size(); i++) {
		int next = tree[x][i];
		if (visited[next]) continue;
		parent[next][0] = x;
		dfs(next, depth + 1);
	}
}

// 전체 부모 관계 설정
void setParent()
{
	dfs(1, 0); // 루트를 0으로 설정

	for (int j = 1; j < LOG; j++) {
		for (int i = 1; i <= n; i++) {
			parent[i][j] = parent[parent[i][j - 1]][j - 1];
		}
	}
}

// 최소 공통 조상을 찾는 함수
int LCA(int x, int y)
{
	// y가 더 깊도록 설정
	if (d[x] > d[y]) {
		swap(x, y);
	}

	// 두 노드의 깊이를 동일하게 맞춰준다
	for (int i = LOG - 1; i >= 0; i--) {
		if (d[y] - d[x] >= (1 << i)) {
			y = parent[y][i];
		}
	}

	// 부모와 같은 경우 반환
	if (x == y) return x;

	for (int i = LOG - 1; i >= 0; i--) {
		// 조상을 향해 거슬러 올라간다
		if (parent[x][i] != parent[y][i]) {
			x = parent[x][i];
			y = parent[y][i];
		}
	}
	// 바로 부모가 찾고자 하는 조상
	return parent[x][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

	setParent();

	cin >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << LCA(a, b) << '\n';
	}

	return 0;
}