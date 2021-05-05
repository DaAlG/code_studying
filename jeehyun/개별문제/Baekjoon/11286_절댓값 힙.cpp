/*
 * 우선순위 큐
 * 11286 절댓값 힙
 */

#include <iostream>
#include <queue>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) // 절댓값이 같을 값때
			return a > b; // 숫자의 우선순위가 높다면 true, 그렇지 않다면 false
		return abs(a) > abs(b); // 절댓값이 작으면 true, 그렇지 않으면 false
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x;
	cin >> n;

	priority_queue<int, vector<int>, compare> pq;
	for (int i = 0; i < n; i++) {
		cin >> x;

		if (x == 0) {
			if (!pq.empty()) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}