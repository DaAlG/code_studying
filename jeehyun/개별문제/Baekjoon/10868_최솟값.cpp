/*
 * 자료구조
 * 10868 최솟값
 */

#include <iostream>
#define MAX 100001
#define INF 1000000000
using namespace std;

int arr[MAX];
int tree[4 * MAX];

int init(int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(node * 2, start, mid), init(node * 2 + 1, mid + 1, end));
}

int getMin(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return INF;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return min(getMin(node * 2, start, mid, left, right), getMin(node * 2 + 1, mid + 1, end, left, right));
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << getMin(1, 1, n, a, b) << '\n';
	}

	return 0;
}