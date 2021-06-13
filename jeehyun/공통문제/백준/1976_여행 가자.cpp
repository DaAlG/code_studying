#include <iostream>
#define MAX 201
using namespace std;

int n, m;
int set[MAX];

// 부모 노드를 가져온다
int getParent(int x)
{
	if (set[x] == x) return x;
	return set[x] = getParent(set[x]);
}

// 부모 노드 병합
void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	
	// 숫자가 더 작은 부모로 병합
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

	cin >> n >> m;

	// 처음엔 자기 자신으로 초기화
	for (int i = 1; i <= n; i++) {
		set[i] = i;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int tmp;
			cin >> tmp;
			// 사이클이 생기지 않는 경우 연결
			if (tmp && !find(i, j))
				unionParent(i, j);
		}
	}

	bool possible = true;
	int parent = 0;

	for (int i = 0; i < m; i++) {
		int v;
		cin >> v;

		if (parent == 0) {
			parent = set[v];
			continue;
		}

		// 부모가 다르면 주어진 여행 경로를 통해 목적지에 갈 수 없다
		if (parent != set[v])
			possible = false;
	}

	if (possible)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}