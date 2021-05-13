/*
 * 우선순위 큐
 * 1715 카드 정렬하기
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
		cin >> tmp;
		pq.push(tmp);
	}

	int answer = 0;
	while (pq.size() > 1) {
		int sum = pq.top(); pq.pop();
		sum += pq.top(); pq.pop();
		answer += sum;
		pq.push(sum);
	}
	cout << answer;

	return 0;
}