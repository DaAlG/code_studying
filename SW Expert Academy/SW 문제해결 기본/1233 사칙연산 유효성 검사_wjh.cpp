// SW Expert Academy
// SW 문제해결 기본 9일차 - 1233 사칙연산 유효성 검사

#include <iostream>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		int N;
		cin >> N;

		int ans = 1;
		char ch;
		for (int i = 1; i <= N; i++) {
			cin >> i >> ch;

			int left, right;
			if (i <= N / 2) { // 연산자는 루트노드이거나 가지노드. 숫자가 있으면 안됨
				if (N % 2 == 0 && i == N / 2)
					cin >> left;
				else
					cin >> left >> right;

				if (ch >= '0' && ch < '9')
					ans = 0;
			}
			else { // 피연산자는 모두 리프노드. 연산자가 있으면 안됨
				if (!(ch >= '0' && ch <= '9'))
					ans = 0;
			}
		}

		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}