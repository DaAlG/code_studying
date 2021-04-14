/*
 * 그리디
 * 11000 강의실 배정
 */

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		int s, t;
		cin >> s >> t;
		time.push_back({ s, t });
	}
	sort(time.begin(), time.end());

	// 수업이 끝나는 시간을 우선순위 큐에 삽입
	priority_queue<int, vector<int>, greater<int>> pq;
	pq.push(time[0].second);
	
	for (int i = 1; i < n; i++) {
		// i번째 수업 시작시간이 top(이전 수업의 끝나는 시간)보다 빠르다면 우선순위 큐에 삽입
		// -> 다른 강의실을 써야함
		if (pq.top() > time[i].first) {
			pq.push(time[i].second);
		}
		else { // top의 수업이 있었던 강의실을 쓸 수 있으므로 pop하고 i번째 수업 끝나는 시간을 넣는다
			pq.pop();
			pq.push(time[i].second);
		}
	}

	cout << pq.size();
	return 0;
}