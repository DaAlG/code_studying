/*
 * 자료구조
 * 2696 중앙값 구하기
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

	int T;
	cin >> T;

	while (T--) {
		int n, k;
		cin >> n;

		vector<int> answer;
		priority_queue<int, vector<int>> maxheap;
		priority_queue<int, vector<int>, greater<int>> minheap;

		for (int i = 1; i <= n; i++) {
			cin >> k;

			// 중앙값을 찾기 위해 두 큐의 크기는 같아야 한다
			if (maxheap.size() == minheap.size())
				maxheap.push(k);
			else
				minheap.push(k);

			// minheap의 top이 더 크면 정렬이 제대로 되지 않은 상태이므로 top끼리 바꿔준다
			if (!maxheap.empty() && !minheap.empty() &&  maxheap.top() > minheap.top()) {
				int maxTop = maxheap.top(); maxheap.pop();
				int minTop = minheap.top(); minheap.pop();
				
				maxheap.push(minTop);
				minheap.push(maxTop);
			}

			if (i % 2) { // 홀수번째 수마다 중앙값 저장
				answer.push_back(maxheap.top());
			}
		}

		cout << answer.size() << '\n';
		for (int i = 0; i < answer.size(); i++) {
			if (i > 0 && i % 10 == 0) cout << '\n';
			cout << answer[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}