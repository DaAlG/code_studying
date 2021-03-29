using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <queue>

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 1;
	vector<int> q;
	int cur_weight = 0;
	queue<int> qu;

	qu.push(truck_weights[0]);
	cur_weight += truck_weights[0];
	q.push_back(bridge_length);
	truck_weights.erase(truck_weights.begin());
	

	while (1) {
		answer++;
		for (int i = 0; i < q.size(); i++)
			q[i] -= 1;
		if (q[0] == 0) {
			q.erase(q.begin());
			cur_weight -= qu.front();
			qu.pop();
		}

		if (truck_weights.empty() == true && cur_weight == 0) break;


		if (!truck_weights.empty()) {
			if (cur_weight + truck_weights[0] <= weight) {
				qu.push(truck_weights[0]);
				cur_weight += truck_weights[0];
				q.push_back(bridge_length);
				truck_weights.erase(truck_weights.begin());
			}
		}
	}
	return answer;
}

int main() {
	int bridge_length = 100;
	int weight = 100;
	vector<int> truck_weights = { 10,10,10,10,10,10,10,10,10,10 };
	cout << solution(bridge_length, weight, truck_weights) << '\n';
}