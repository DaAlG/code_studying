#include <string>
#include <vector>

using namespace std;

bool visited[MAX];

void dfs(vector<vector<int>>& computers, int now) {
    visited[now] = true;

    for (int i = now, j = 0; j < computers.size(); j++) {
        if (i == j) continue;

        if (!visited[j] && computers[i][j]) {
            dfs(computers, j);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            answer++;
            dfs(computers, i);
        }
    }

    return answer;
}