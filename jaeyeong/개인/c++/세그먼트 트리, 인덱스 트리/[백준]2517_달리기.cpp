using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 500000
//★리라벨링, 세그먼트 트리
typedef pair<int, int> pii;

int n, num;
pii player[MAX];
/*
* h = ceil(log2(n))
* tree_size = 1<<(h+1)
* seg_tree[tree_size]
*/
int seg_tree[1 << 20];

//구간이 s~e이고, 구해야하는 합의 범위는 left~right
int seg_num(int node, int s, int e, int l, int r) { 
	if (r < s || e < l) return 0;
	if (l <= s && e <= r) {
		return seg_tree[node];
	}
	else {
		return seg_num(node * 2, s, (s + e) / 2, l, r) + seg_num(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
	}
}

void update(int node, int s, int e, int idx, int v) {
	if (idx < s || e < idx) return;
	if (s == e) {
		seg_tree[node] = v;
	}
	else {
		update(node * 2, s, (s + e) / 2, idx, v);
		update(node * 2 + 1, (s + e) / 2 + 1, e, idx, v);
		seg_tree[node] = seg_tree[node * 2] + seg_tree[node * 2 + 1];
	}
}
bool comp(pii p1, pii p2) {
	return p1.second < p2.second;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int power;
		cin >> power;
		player[i].first = i;
		player[i].second = power;
	}
	//sort power => relabeling
	sort(player, player + n, comp); //능력치 낮은순 정렬

	for (int i = 0; i < n; i++)
		player[i].second = ++num;

	// sort original order
	sort(player, player + n);

	for (int i = 0; i < n; i++) {
		int curPower = player[i].second;
		int cnt = 0;
		if (curPower > 1) {
			cnt = seg_num(1, 1, num, 1, curPower - 1);
		}
		update(1, 1, num, curPower, 1);
		cout << i + 1 - cnt << '\n';
	}
}