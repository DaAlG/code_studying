/*
 * 자료구조
 * 11866 요세푸스 문제 0
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	cout << "<";
	while (!q.empty()) {
		for (int i = 0; !q.empty() && i < k - 1; i++) {
			q.push(q.front());
			q.pop();
		}

		cout << q.front();
		if (q.size() > 1)
			cout << ", ";
		q.pop();
	}
	cout << ">";

	return 0;
}