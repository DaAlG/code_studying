using namespace std;
#include <iostream>
#include <vector>
/*
preorder:	루트LR
inorder:	L루트R
postorder:	LR루트
포스트오더에서 가장 마지막 노드는 루트이다.
인오더에서 루트를 찾으면 L과 R을 구분할 수 있다.
인오더에서 특정 값을 찾기 위해선 인오더의 크기 n만큼의 시간이 걸리고,
전체를 찾기 위해선 n^2의 시간이 걸린다. 이를 단축하기 위해(O(1)의 시간으로 찾기 위해)
각 노드의 위치를 기록하는 pos라는 배열을 사용한다.
*/
vector<int> in, post, pos;

void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = post[post_end];
	cout << root << ' ';
	int p = pos[root]; //인오더에서 루트의 위치
	//post_end는 루트(포스트오더의 마지막은 루트)
	int left = p - in_start;	//left child의 수
	//int right = in_end - p;	//right child의 수
	solve(in_start, p - 1, post_start, post_start+left-1);
	solve(p + 1, in_end, post_start + left, post_end - 1);
}
int main() {
	int n;
	cin >> n;
	in.resize(n);
	post.resize(n);
	pos.resize(n+1);
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		pos[in[i]] = i;
	}
	for (int i = 0; i < n; i++)
		cin >> post[i];
	solve(0, n - 1, 0, n - 1);
	return 0;
}