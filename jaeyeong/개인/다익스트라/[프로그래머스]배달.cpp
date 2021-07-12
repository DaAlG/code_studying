#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<pair<int, int>> graph[51]; //간선 정보(거리, 도착노드)
int d[51];

void dijkstra(int maxNode) {
    d[1] = 1;
    priority_queue<pair<int, int>> pq; //(거리, 현재노드)
    pq.push(make_pair(0, 1));
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        if (d[cur] < dist) continue;
        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].second;
            int nextDistance = dist + graph[cur][i].first;
            if (nextDistance < d[next]) {
                d[next] = nextDistance;
                pq.push(make_pair(-nextDistance, next));
            }
        }
    }
}
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    int maxNode = -1;

    //그래프 세팅
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        graph[a].push_back(make_pair(c, b));
        graph[b].push_back(make_pair(c, a));
        maxNode = max(maxNode, max(a, b));
    }
    for (int i = 1; i <= maxNode; i++)
        d[i] = 0x3f3f3f3f;

    dijkstra(maxNode);
    for (int i = 1; i <= maxNode; i++) {
        if (d[i] <= K) answer++;
    }
    return answer;
}