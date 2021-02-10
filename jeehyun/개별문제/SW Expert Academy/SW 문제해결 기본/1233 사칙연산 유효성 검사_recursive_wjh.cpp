// SW Expert Academy
// SW 문제해결 기본 9일차 - 1233 사칙연산 유효성 검사

#include <iostream>

using namespace std;

char tree[201];
int len;

// VLR
bool preorder(int n)
{
	if (n <= len) {
		switch (tree[n / 2]) {
		case '+':
			break;
		case '-':
			break;
		case '*':
			break;
		case '/':
			break;
		default:
			return false;
		}

		if (!preorder(n * 2))
			return false;

		if (!preorder(n * 2 + 1))
			return false;
	}

	return true;
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

		int ans = preorder(2);
		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}