using namespace std;
#include <iostream>
#define MAX 1001

int n;
int preorder[MAX], inorder[MAX];

void solve(int root, int l, int r) {
	if (l > r) return;
	int k = inorder[preorder[root]];
	solve(root+1 , l, k - 1); //left subtree
	solve(root + k + 1 - l, k+1, r); //right subtree
	cout << preorder[root] << ' ';
}
int main() {
	int tc, x;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> preorder[i];
		for (int i = 0; i < n; i++) {
			cin >> x;
			inorder[x] = i;
		}
		solve(0, 0, n-1);
		cout << '\n';
	}
}