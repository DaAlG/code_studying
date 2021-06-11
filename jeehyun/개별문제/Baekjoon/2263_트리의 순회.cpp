/* 
 * 분할 정복
 * 2263 트리의 순회
 */

#include <iostream>
#define MAX 100001
using namespace std;

int in[MAX]; // inorder
int post[MAX]; // postorder
int idx[MAX]; // inorder에서 index 정보 저장

/*void preorder(int start, int end, int root)
{
	for (int i = start; i < end; i++) {
		if (in[i] == post[root]) {
			cout << post[root] << ' ';
			// root에서 오른쪽 서브트리 노드수만큼 빼준다
			preorder(start, i, root - end + i);
			preorder(i + 1, end, root - 1);
		}
	}
}*/

void preorder(int in_left, int in_right, int po_left, int po_right)
{
	// 더 이상 분해할 수 없는 경우 종료
	if (in_left > in_right || po_left > po_right) return;

	// postoder의 마지막 값이 root
	int rootIdx = idx[post[po_right]];

	// 왼쪽 서브트리 노드 개수
	int left = rootIdx - in_left;

	cout << in[rootIdx] << ' ';

	// 왼쪽
	preorder(in_left, rootIdx - 1, po_left, po_left + left - 1);
	// 오른쪽
	preorder(rootIdx + 1, in_right, po_left + left, po_right - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> in[i];
	for (int i = 0; i < n; i++) cin >> post[i];
	for (int i = 0; i < n; i++) idx[in[i]] = i;

	//preorder(0, n, n - 1);
	preorder(0, n - 1, 0, n - 1);

	return 0;
}