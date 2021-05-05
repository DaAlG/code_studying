#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> Job;

struct compare {
    bool operator()(int a, int b) {
        return  Job[a][1] > Job[b][1];
    }
};
priority_queue<int, vector<int>, compare> ready_queue;

int solution(vector<vector<int>> jobs) {
    int answer = 0, cnt=0;
    int idx = 0, c;
    int n = jobs.size();

    sort(jobs.begin(), jobs.end());

    Job.resize(n, vector<int>(jobs[0].size(), 0));
    copy(jobs.begin(), jobs.end(), Job.begin());

    ready_queue.push(idx++);
    c = jobs[0][0];
    while (cnt<n) {
        if (ready_queue.empty()) {
            ready_queue.push(idx++);
            if (jobs[idx-1][0] > c)
                c = jobs[idx-1][0];
        }
        while (idx<n &&jobs[idx][0] <= c) {
            ready_queue.push(idx++);
        }
        c += jobs[ready_queue.top()][1];
        answer += c - jobs[ready_queue.top()][0];
        ready_queue.pop();
        cnt++;
    }
    return answer/n;
}

int main() {
    vector<vector<int>> jobs = { {0,3},{1,9},{2,6} };
    cout << solution(jobs);
}