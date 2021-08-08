#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
#define TRAPMAX 10
#define INF 987654321
using namespace std;

struct Edge {
    int v, c, reversed;
    Edge(int v, int c, int reversed) {
        this->v = v;
        this->c = c;
        this->reversed = reversed;
    }
};

vector<Edge> graph[MAX];
bool trap[MAX];
int trapIdx[MAX];
int d[MAX][1 << TRAPMAX]; // 함정의 상태가 state인 상황에서 정점을 방문했을 때 걸리는 최단시간

int findCase(int cur, int next, int state) 
{
    if (trap[cur] == false && trap[next] == false) return 1; // 둘 다 함정 X
    if (trap[cur] == false && trap[next] == true) return 2; // cur이 함정이 아니고 next가 함정
    if (trap[cur] == true && trap[next] == false) return 3; // cur이 함정이고 next가 함정 X
    if (trap[cur] == true && trap[next] == true) return 4; // 둘 다 함정
}

bool trapState(int next, int state)
{
    if ((state & (1 << trapIdx[next])) == false) return false;
    return true;
}

int trapOn(int state, int idx) 
{ 
    return state | (1 << trapIdx[idx]);
}

int trapOff(int state, int idx) 
{
    return state ^ (1 << trapIdx[idx]);
}

void dijkstra(int start) 
{
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ 0, {start, 0} });
    d[start][0] = 0;

    while (!pq.empty()) {
        int cur = pq.top().second.first;
        int dist = -pq.top().first;
        int state = pq.top().second.second;
        pq.pop();

        for (int i = 0; i < graph[cur].size(); i++) {
            int next = graph[cur][i].v;
            int nextDist = dist + graph[cur][i].c;
            int eState = graph[cur][i].reversed;
            int nextState = state;

            int result = findCase(cur, next, state);
            if (result == 1) { // 원래 방향대로만 이동할 수 있음
                if (eState && nextDist < d[next][nextState]) {
                    d[next][nextState] = nextDist;
                    pq.push({ -nextDist, {next, nextState } });
                }
            }
            else if (result == 2) {
                bool nextTState = trapState(next, state);
                if (eState != nextTState) {
                    if (nextTState) nextState = trapOff(nextState, next);
                    else nextState = trapOn(nextState, next);

                    if (nextDist < d[next][nextState]) {
                        d[next][nextState] = nextDist;
                        pq.push({ -nextDist, {next, nextState } });
                    }
                }
            }
            else if (result == 3) {
                bool curTState = trapState(cur, state);
                if (eState != curTState && nextDist < d[next][nextState]) {
                    d[next][nextState] = nextDist;
                    pq.push({ -nextDist, {next, nextState } });
                }
            }
            else if (result == 4) {
                bool curTState = trapState(cur, state);
                bool nextTState = trapState(next, state);

                if ((curTState == nextTState && eState) || (curTState != nextTState && !eState)) {
                    if (nextTState) nextState = trapOff(nextState, next);
                    else nextState = trapOn(nextState, next);

                    if (nextDist < d[next][nextState]) {
                        d[next][nextState] = nextDist;
                        pq.push({ -nextDist, {next, nextState } });
                    }
                }
            }
        }
    }
}

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) 
{
    for (int i = 0; i < traps.size(); i++) {
        int k = traps[i];
        trap[k] = true;
        trapIdx[k] = i;
    }

    for (int i = 1; i <= n; i++) fill(d[i], d[i] + 1030, INF);
    for (int i = 0; i < roads.size(); i++) {
        int a = roads[i][0];
        int b = roads[i][1];
        int c = roads[i][2];
        graph[a].push_back(Edge(b, c, 1));
        graph[b].push_back(Edge(a, c, 0));
    }

    dijkstra(start);

    int answer = INF;
    for (int i = 0; i < (1 << TRAPMAX); i++) {
        answer = min(answer, d[end][i]);
    }
    return answer;
}