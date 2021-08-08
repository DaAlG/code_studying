/*
 * 세그먼트 트리
 * 1275 커피숍2
 */

#include <iostream>
#define MAX 100001
using namespace std;

int n, q;
long long arr[MAX];
long long tree[MAX * 4];

long long init(int node, int start, int end) 
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(2 * node, start, mid) + init(2 * node + 1, mid + 1, end);
}

void update(int node, int start, int end, int index, long long diff) 
{
	if (index < start || index > end) return;

	tree[node] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(2 * node, start, mid, index, diff);
	update(2 * node + 1, mid + 1, end, index, diff);
}

long long sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(2 * node, start, mid, left, right) + sum(2 * node + 1, mid + 1, end, left, right);
}

int main() 
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) cin >> arr[i];
	init(1, 1, n);

	while (q--) {
		int x, y, a, b;
		cin >> x >> y >> a >> b;

		if (x > y) {
			int tmp = x;
			x = y;
			y = tmp;
		}

		cout << sum(1, 1, n, x, y) << "\n";

		update(1, 1, n, a, b - arr[a]);
		arr[a] = b;
	}

	return 0;
}