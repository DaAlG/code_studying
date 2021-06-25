/*
 * 자료구조
 * 2042 구간 합 구하기
 */

#include <iostream>
using namespace std;

int n, m, k;
long long arr[1000001];
long long tree[(1 << 21)]; // MAX = 1,000,000, h = ceil(log2(MAX)) = 20이므로 tree 사이즈는 1 << 21

// 세그먼트 트리 초기화
long long init(int node, int start, int end) // 현재 노드번호, 시작 인덱스, 끝 인덱스
{
	if (start == end) 
		return tree[node] = arr[start];
	
	int mid = (start + end) / 2;
	// 재귀적으로 두 부분으로 나눈 뒤에 그 합을 자기 자신으로 한다
	return tree[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

// 현재 노드번호, 시작 인덱스, 끝 인덱스, 구간 합을 구하고자 하는 범위 (left ~ right)
long long sum(int node, int start, int end, int left, int right)
{
	// 범위 밖에 있는 경우
	if (left > end || right < start) return 0;

	// 범위 안에 있는 경우
	if (left <= start && end <= right) return tree[node];

	// 그렇지 않다면 두 부분으로 나누어 합을 구하기
	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

// 현재 노드번호, 시작 인덱스, 끝 인덱스, 구간 합을 수정하고자 하는 노드, 수정할 값
void update(int node, int start, int end, int index, long long diff)
{
	// 범위 밖에 있는 경우
	if (index < start || index > end) return;

	// 범위 안에 있으면 내려가며 다른 원소도 갱신
	tree[node] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	update(node * 2, start, mid, index, diff);
	update(node * 2 + 1, mid + 1, end, index, diff);
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
		int a, b;
		long long c;
		cin >> a >> b >> c;

		if (a == 1) {
			update(1, 1, n, b, c - arr[b]);
			arr[b] = c;
		}
		else 
			cout << sum(1, 1, n, b, c) << '\n';
	}

	return 0;
}