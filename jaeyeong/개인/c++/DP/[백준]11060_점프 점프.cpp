using namespace std;
#include <iostream>
#include <queue>

int d[1001];
vector<int> arr[1001];

int dijkstra(int n) {
	int min = 100000;
	d[1] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, 1));//점프횟수, 노드
	while (pq.empty() == false) {
		int jump = -pq.top().first;
		int current = pq.top().second;
		pq.pop();
		if (d[current] < jump) continue;
		for (int i = 0; i < arr[current].size(); i++) {
			int next = arr[current][i];
			int nextDistance = 1 + jump;
			if (nextDistance < d[next]) {
				d[next] = nextDistance;
				pq.push(make_pair(-nextDistance, next));
			}
		}
	}
	if (d[n] >= 10001)
		d[n] = -1;
	return d[n];
}
int main() {
	int input[1001], n;
	

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= n; i++) {
		d[i] = 10001;
		for (int j = 1; j <= input[i]; j++) {
			arr[i].push_back(i+j);
		}
	}
	cout << dijkstra(n) << '\n';
}