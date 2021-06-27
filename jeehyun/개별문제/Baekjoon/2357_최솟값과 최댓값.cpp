/*
 * 자료구조
 * 2357 최솟값과 최댓값
 */

#include <iostream>
#define MAX 100000
#define INF 1000000001
using namespace std;

int n, m;
int arr[MAX + 1];
int tree[4 * MAX];
int tree_min[4 * MAX];

void init(int node, int start, int end)
{
	if (start == end) {
		tree[node] = arr[start];
		tree_min[node] = arr[start];
		return;
	}
	
	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);

	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	tree_min[node] = min(tree_min[node * 2], tree_min[node * 2 + 1]);
}

int getMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree_min[node];

	int mid = (start + end) / 2;
	return min(getMin(node * 2, start, mid, left, right), getMin(node * 2 + 1, mid + 1, end, left, right));
}

int getMax(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return max(getMax(node * 2, start, mid, left, right), getMax(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << getMin(1, 1, n, a, b) << ' ';
		cout << getMax(1, 1, n, a, b) << '\n';
	}
	return 0;
}