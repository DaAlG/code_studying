#include <iostream>
#include <vector>
#include <queue>
#define INF 500000
using namespace std;

vector<pair<int, int>> graph[51];

int solution(int N, vector<vector<int>> road, int K) {
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0];
        int b = road[i][1];
        int c = road[i][2];
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    priority_queue<pair<int, int>> pq;
    vector<int> d(N + 1, INF);

    d[1] = 0;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cur = pq.top().second;
        int dist = -pq.top().first;
        pq.pop();

        if (d[cur] < dist)
            continue;

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].first;
            int nDist = dist + graph[cur][i].second;

            if (d[next] > nDist) {
                d[next] = nDist;
                pq.push({ -nDist, next });
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= N; i++) {
        if (d[i] <= K)
            answer++;
    }

    return answer;
}