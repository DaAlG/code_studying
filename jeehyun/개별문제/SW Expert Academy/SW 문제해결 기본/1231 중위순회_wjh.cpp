// SW Expert Academy
// SW 문제해결 기본 9일차 - 1231 중위순회

#include <iostream>

using namespace std;

char tree[101];
int len;

// LVR
void inorder(int n)
{
	if (n <= len) {
		inorder(n * 2);
		cout << tree[n];
		inorder(n * 2 + 1);
	}
}

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> len;
		
		for (int i = 1; i <= len; i++) {
			cin >> i >> tree[i];

			int left, right;
			if (i < len / 2) {
				cin >> left >> right;
			}
			else if (i == len / 2) {
				if (len % 2)
					cin >> left >> right;
				else
					cin >> left;
			}
		}

		cout << "#" << test_case << " ";
		inorder(1);
		cout << endl;
	}

	return 0;
}