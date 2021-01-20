#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
void init(vector<int>& tree, vector<int>& a, int node, int start, int end) {
    if (start == end)
        tree[node] = a[start];
    else {
        init(tree, a, node * 2, start, (start + end) / 2);
        init(tree, a, node * 2 + 1, (start + end) / 2 + 1, end);
        tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
    }
 }
int query(vector<int>& tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return -1;
    }
    if (i <= start && end <= j)
        return tree[node];
    int m1 = query(tree, 2 * node, start, (start + end) / 2, i, j);
    int m2 = query(tree, 2 * node + 1, (start + end) / 2 + 1, end, i, j);
    if (m1 == -1) return m2;
    else if (m2 == -1) return m1;
    else return min(m1, m2);
}
void update(vector<int>& tree, int node, int start, int end, int index, int value) {
    if (index < start || end < index) return;
    if (start == end) {
        tree[node] = value;
        return;
    }
    update(tree, node * 2, start, (start + end) / 2, index, value);
    update(tree, node * 2 + 1, (start + end) / 2 + 1, end, index, value);
    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n;
    vector<int> a(n + 1);
    int h = (int)ceil(log2(n));
    int tree_size(1 << (h + 1));
    vector<int> tree(tree_size);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> m;
    init(tree, a, 1, 1, n);
    while (m--) {
        int w;
        cin >> w;
        if (w == 1) {
            int index, value;
            cin >> index >> value;
            update(tree, 1, 1, n, index, value);
        }
        else {
            int start, end;
            cin >> start>> end;
            cout << query(tree, 1, 1, n, start, end) << '\n';
        }
    }
    return 0;
}