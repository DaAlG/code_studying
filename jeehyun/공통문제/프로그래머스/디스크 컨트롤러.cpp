#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> pii;

int solution(vector<vector<int>> jobs) {
    int n = jobs.size();
    int answer = 0;
    int idx = 0;
    int now = 0;

    sort(jobs.begin(), jobs.end());
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    while (idx < n || !pq.empty()) {
        if (idx < n && jobs[idx][0] <= now) {
            pq.push({ jobs[idx][1], jobs[idx++][0] });
            continue;
        }

        if (!pq.empty()) {
            now += pq.top().fi;
            answer += now - pq.top().se;
            pq.pop();
        }
        else {
            now = jobs[idx][0];
        }
    }
    return answer / n;
}