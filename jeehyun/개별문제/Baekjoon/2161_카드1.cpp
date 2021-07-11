/*
 * 자료구조
 * 2161 카드1
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	queue<int> q;
	for (int i = 1; i <= n; i++) q.push(i);

	while (q.size() > 1) {
		cout << q.front() << ' ';
		q.pop();
		q.push(q.front());
		q.pop();
	}
	cout << q.front();
	return 0;
}