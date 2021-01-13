// SW Expert Academy
// SW 문제해결 기본 9일차 - 1232 사칙연산

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int tree[1001][3];
int len;

// LRV
int postorder(int n)
{
	if (tree[n][0] < 0) {
		int a = postorder(tree[n][1]);
		int b = postorder(tree[n][2]);

		int res;
		switch (tree[n][0]) {
		case -1:
			res = a + b;
			break;
		case -2:
			res = a - b;
			break;
		case -3:
			res = a * b;
			break;
		case -4:
			res = a / b;
			break;
		}

		return res;
	}

	return tree[n][0];
}

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> len;

		for (int i = 1; i <= len; i++) {
			//cin >> i >> tree[i];
			char ch;
			scanf("%d %c", &i, &ch);

			if (ch >= '0' && ch <= '9') {
				tree[i][0] = ch - '0';
				ch = getchar();
				while (ch >= '0' && ch <= '9') {
					tree[i][0] = tree[i][0] * 10 + ch - '0';
					ch = getchar();
				}
			}
			else {
				switch (ch) {
				case '+':
					tree[i][0] = -1;
					break;
				case '-':
					tree[i][0] = -2;
					break;
				case '*':
					tree[i][0] = -3;
					break;
				case '/':
					tree[i][0] = -4;
					break;
				}

				scanf("%d %d", &tree[i][1], &tree[i][2]);
			}
		}

		cout << "#" << test_case << " " << postorder(1) << endl;
	}

	return 0;
}