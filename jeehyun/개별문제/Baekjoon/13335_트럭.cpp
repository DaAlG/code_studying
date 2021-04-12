#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int truck[MAX];

int main()
{
	int n, w, L; // 트럭의 수, 다리의 길이, 다리의 최대하중
	cin >> n >> w >> L;

	
	for (int i = 0; i < n; i++) {
		cin >> truck[i];
	}

	queue<pair<int, int>> q;
	q.push({ 0, 1 });
	
	// 첫번째 트럭이 건너기 시작했으므로 1
	int answer = 1; 
	int index = 1;
	
	while (!q.empty()) {
		answer++;
		int size = q.size();
		int sum = 0;

		for (int i = 0; i < size; i++) {
			int cur = q.front().first;
			int pos = q.front().second;
			q.pop();

			// 다리를 건너는 중이라면 계속 이동
			if (pos < w) {
				q.push({ cur, pos + 1 });
				sum += truck[cur];
			}
		}

		// 다리가 다음 트럭의 무게를 견딜 수 있으면 이동 시작
		if (index < n && sum + truck[index] <= L) {
			q.push({ index, 1 });
			index++;
		}
	}

	cout << answer;
	return 0;
}