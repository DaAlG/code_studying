/*
 * 자료구조
 * 1655 가운데를 말해요
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
	cin >> n;

	priority_queue<int> maxheap; // 중간값보다 작음
	priority_queue<int, vector<int>, greater<int>> minheap; // 중간값보다 큼
	
	for (int i = 1; i <= n; i++) {
		cin >> k;

		if (maxheap.size() == minheap.size())
			maxheap.push(k);
		else
			minheap.push(k);

		if (!maxheap.empty() && !minheap.empty() && minheap.top() < maxheap.top()) {
			int a = minheap.top();
			int b = maxheap.top();

			minheap.pop(); maxheap.pop();

			minheap.push(b);
			maxheap.push(a);
		}

		cout << maxheap.top() << '\n';
	}

	return 0;
}