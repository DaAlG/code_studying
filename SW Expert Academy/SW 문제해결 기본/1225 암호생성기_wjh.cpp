// SW Expert Academy
// S/W 문제해결 기본 7일차 - 1225 암호생성기

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int test_case;
	int T = 10;

	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> test_case;

		int num;
		queue<int> q;

		for (int i = 0; i < 8; i++) {
			cin >> num;
			q.push(num);
		}

		int check = 1;
		while (check) {
			for (int i = 1; i <= 5; i++) {
				int front = q.front() - i;
				q.pop();

				if (front <= 0) {
					check = 0;
					q.push(0);
					break;
				}
				else
					q.push(front);
			}
		}

		cout << "#" << test_case << " ";
		for (int i = 0; i < 8; i++) {
			cout << q.front() << " ";
			q.pop();
		}
		cout << endl;
	}

	return 0;
}