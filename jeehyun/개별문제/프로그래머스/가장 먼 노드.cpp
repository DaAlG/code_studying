#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> bfs(vector<vector<int>>& graph, int n, int start) {
    vector<int> dist(n + 1, -1);
    queue<int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i];
            if (dist[next] == -1) {
                dist[next] = dist[cur] + 1;
                q.push(next);
            }
        }
    }

    return dist;
}

int solution(int n, vector<vector<int>> edge) {
    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < edge.size(); i++) {
        int u = edge[i][0];
        int v = edge[i][1];
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> dist = bfs(graph, n, 1);
    auto maxDist = max_element(dist.begin(), dist.end());

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == *maxDist)
            answer++;
    }

    return answer;
}