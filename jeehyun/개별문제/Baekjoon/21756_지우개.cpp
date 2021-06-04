/*
 * 구현
 * 21756 지우개
 */

#include <iostream>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	deque<int> dq;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}

	while (dq.size() > 1) {
		int size = dq.size();

		for (int i = 1; i <= size; i++) {
			int k = dq.front();
			dq.pop_front();

			// 홀수번 칸의 수들은 모두 지우고 남은 수들을 왼쪽으로 모은다
			if (i % 2 == 0)
				dq.push_back(k);
		}
	}
	cout << dq.front();

	return 0;
}