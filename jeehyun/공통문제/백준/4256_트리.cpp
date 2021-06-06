#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int pre[MAX];
int in[MAX];

void postOrder(int start, int end, int root)
{
	for (int i = start; i < end; i++) {
		if (in[i] == pre[root]) {
			// 왼쪽 서브트리
			postOrder(start, i, root + 1);
			// 오른쪽 서브트리 루트 -> i - start + 1 == 왼쪽 서브트리 노드 개수 + 루트
			postOrder(i + 1, end, root + i - start + 1);
			cout << pre[root] << ' ';
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		fill_n(pre, MAX, 0);
		fill_n(in, MAX, 0);

		for (int i = 0; i < n; i++) cin >> pre[i];
		for (int i = 0; i < n; i++) cin >> in[i];

		postOrder(0, n, 0);
		cout << '\n';
	}

	return 0;
}