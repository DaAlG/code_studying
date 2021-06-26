/*
 * 자료구조
 * 11505 구간 곱 구하기
 */

#include <iostream>
#define MAX 1000000
#define MOD 1000000007
using namespace std;

int n, m, k;
int arr[MAX + 1];
long long tree[4 * MAX];

long long init(int node, int start, int end)
{
	if (start == end) return tree[node] = arr[start];

	int mid = (start + end) / 2;
	return tree[node] = init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end) % MOD;
}

long long update(int node, int start, int end, int index, long long num)
{
	if (index < start || index > end) return tree[node];
	if (start == end) return tree[node] = num;
	
	int mid = (start + end) / 2;
	return tree[node] = update(node * 2, start, mid, index, num) * update(node * 2 + 1, mid + 1, end, index, num) % MOD;
}

long long mult(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return mult(node * 2, start, mid, left, right) * mult(node * 2 + 1, mid + 1, end, left, right) % MOD;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> arr[i];

	init(1, 1, n);

	for (int i = 0; i < m + k; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		if (a == 1) {
			arr[b] = c;
			update(1, 1, n, b, c);
		}
		else 
			cout << mult(1, 1, n, b, c)  % MOD << '\n';
	}
	return 0;
}