#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
vector<bool> visited; // 티켓 사용 여부
vector<string> answer; // 방문하는 공항 경로

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.second < b.second;
}

bool dfs(vector<vector<string>>& tickets, string now, int cnt) {
    if (cnt == n)
        return true;

    // 다음 공항 후보 탐색
    vector<pair<int, string>> next;
    for (int i = 0; i < n; i++) {
        // 현재 공항에서 갈 수 있는 경로 중 아직 티켓을 쓰지 않은 곳을 찾는다
        if (tickets[i][0] == now && !visited[i]) {
            next.push_back({ i, tickets[i][1] });
        }
    }

    // 알파벳 순서대로 정렬
    sort(next.begin(), next.end(), cmp);

    for (pair<int, string> nxt : next) {
        visited[nxt.first] = true;
        answer.push_back(nxt.second);

        if (dfs(tickets, nxt.second, cnt + 1))
            return true;

        visited[nxt.first] = false;
        answer.pop_back();
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    n = tickets.size();
    visited.resize(n);

    answer.push_back("ICN");
    dfs(tickets, "ICN", 0);
    return answer;
}