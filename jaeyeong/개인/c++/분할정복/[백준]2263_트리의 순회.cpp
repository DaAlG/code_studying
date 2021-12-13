using namespace std;
#include <iostream>
#include <vector>
/*
preorder:	��ƮLR
inorder:	L��ƮR
postorder:	LR��Ʈ
����Ʈ�������� ���� ������ ���� ��Ʈ�̴�.
�ο������� ��Ʈ�� ã���� L�� R�� ������ �� �ִ�.
�ο������� Ư�� ���� ã�� ���ؼ� �ο����� ũ�� n��ŭ�� �ð��� �ɸ���,
��ü�� ã�� ���ؼ� n^2�� �ð��� �ɸ���. �̸� �����ϱ� ����(O(1)�� �ð����� ã�� ����)
�� ����� ��ġ�� ����ϴ� pos��� �迭�� ����Ѵ�.
*/
vector<int> in, post, pos;

void solve(int in_start, int in_end, int post_start, int post_end) {
	if (in_start > in_end || post_start > post_end) return;
	int root = post[post_end];
	cout << root << ' ';
	int p = pos[root]; //�ο������� ��Ʈ�� ��ġ
	//post_end�� ��Ʈ(����Ʈ������ �������� ��Ʈ)
	int left = p - in_start;	//left child�� ��
	//int right = in_end - p;	//right child�� ��
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