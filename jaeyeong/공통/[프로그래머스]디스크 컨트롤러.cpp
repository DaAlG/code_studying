using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


struct compare {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

int solution(vector<vector<int>> jobs) {
	int answer = 0, idx=0;
	priority_queue<vector<int>, vector<vector<int>>, compare> pq;
	int n = jobs.size();

	sort(jobs.begin(), jobs.end());
	int curTime = jobs[0][0];
	while (idx < n || !pq.empty()) {
		if (idx < jobs.size() && jobs[idx][0] <= curTime) {
			pq.push(jobs[idx++]);
			continue;
		}
		if (!pq.empty()) {
			curTime += pq.top()[1];
			answer += (curTime - pq.top()[0]);
			pq.pop();
		}
		else curTime = jobs[idx][0];
	}
	return answer / n;
}
int main() {
	vector<vector<int>> jobs = { {0,3}, {1,9}, {2,6} };
	solution(jobs);
}