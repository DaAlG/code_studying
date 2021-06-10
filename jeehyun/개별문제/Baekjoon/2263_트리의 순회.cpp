/* 
 * 분할 정복
 * 2263 트리의 순회
 */

#include <iostream>
#define MAX 100001
using namespace std;

int in[MAX];
int post[MAX];

void preorder(int start, int end, int root)
{
	for (int i = start; i < end; i++) {
		if (in[i] == post[root]) {
			cout << post[root] << ' ';
			preorder(start, i, root - end + i);
			preorder(i + 1, end, root - 1);
		}
	}
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

	preorder(0, n, n - 1);

	return 0;
}