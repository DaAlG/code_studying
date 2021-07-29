#include <iostream>
#include <vector>
#include <queue>
#define MAX 101
using namespace std;

vector<int> graph[MAX];
int level[MAX];

void init()
{
    for (int i = 1; i < MAX; i++) {
        graph[i].clear();
        level[i] = 0;
    }
}

void bfs(int start)
{
    queue<int> q;
    q.push(start);
    level[start] = 1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int i = 0; i < graph[v].size(); i++) {
            int next = graph[v][i];
            if (level[next] == 0) { // 아직 연락을 받지 않은 사람에게 연락
                level[next] = level[v] + 1;
                q.push(next);
            }
        }
    }
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int e, start;
        cin >> e >> start;
        init();

        // 연락 가능한 방향 저장
        for (int i = 0; i < e / 2; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
        }

        bfs(start);

        int lastVisited = 0;
        for (int i = 1; i < MAX; i++) {
            // level[i]가 가장 큰 번호가 가장 나중에 연락 받은 사람이다
            // 여러 명 있을 경우 가장 번호가 큰 사람을 찾아야 하므로 level[lastVisited] 이상이면 갱신
            if (level[i] >= level[lastVisited]) {
                lastVisited = i;
            }
        }
        cout << "#" << test_case << " " << lastVisited << "\n";
    }
    return 0;
}