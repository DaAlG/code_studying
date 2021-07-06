/*
 * 자료구조
 * 11003 최솟값 찾기
 */

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, L, k;
	cin >> n >> L;
	
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

	for (int i = 0; i < n; i++) {
		cin >> k;

		// 범위에 있는 값이 아니라면 pop
		while (!pq.empty() && pq.top().second < i - L + 1) {
			pq.pop();
		}

		pq.push({ k, i });
		cout << pq.top().first << ' ';
	}

	return 0;
}