using namespace std;
#include <string>
#include <vector>
#include <iostream>
#include <queue>

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int size = progresses.size();
    vector<pair<int, int>> q;
    int ans;
    for (int i = 0; i < size; i++)
        q.push_back(make_pair(progresses[i], speeds[i]));
    while (!q.empty()) {
        for (int i = 0; i < size; i++) {
            if (q[i].first >= 100) continue;
            q[i].first += q[i].second;
        }
        ans = 0;
        while(!q.empty() && q[0].first >= 100) {
            ans++;
            q.erase(q.begin());
        }
        if (ans != 0) {
            answer.push_back(ans);
            size = q.size();
        }
    }
    return answer;
}

int main() {
    vector<int> progresses = { 95, 90, 99, 99, 80, 99 };
    vector<int> speeds = { 1, 1, 1, 1, 1, 1 };
    vector<int> ans = solution(progresses, speeds);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << ' ';
}