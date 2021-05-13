/*
 * 우선순위 큐
 * 2075 N번째 큰 수
 */

#include <iostream>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, tmp;
	cin >> n;

	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tmp;
			if (pq.size() == n && pq.top() < tmp) {
				pq.pop();
				pq.push(tmp);
			}
			else if (pq.size() < n) {
				pq.push(tmp);
			}
		}
	}

	cout << pq.top();
	return 0;
}