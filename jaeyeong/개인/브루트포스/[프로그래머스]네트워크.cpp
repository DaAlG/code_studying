using namespace std;
#include <string>
#include <vector>
#include <iostream>

vector<int> graph[200];
bool visit[200];

void dfs(int c) {
    if (visit[c]) return;
    visit[c] = true;
    for (int i = 0; i < graph[c].size(); i++) {
        if (graph[c][i] == c) continue;
        dfs(graph[c][i]);
    }
}
int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (computers[i][j] == 1) {
                graph[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!visit[i]) {
            dfs(i);
            answer++;
        }
    }
    return answer;
}

int main() {
    int n = 4;
    vector<vector<int>> computers = {  {1,0,0,0},
                                       {0,1,0,0},
                                       {0,0,1,1},
                                        {0,0,1,1}
                                    };
    cout << solution(n, computers) << '\n';
}