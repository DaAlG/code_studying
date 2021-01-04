#include<iostream>
#include<string.h>

using namespace std;
int road_no, from, to;
int graph[100][2];
int visited[100];
int check;

void dfs(int start) {
    for (int i = 0; i < 2; i++) {
        int next = graph[start][i];
        if (graph[next][0] == 99 || graph[next][1] == 99) {
            check = 1;
            break;
        }
        else {
            for (int j = 0; j < 2; j++) {
                if (graph[next][j] != -1 && visited[next] == 0) {
                    visited[next] = 1;
                    dfs(next);
                    visited[next] = 0;
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    //freopen("input.txt", "r", stdin);
    T = 10;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> test_case >> road_no;
        cout << "#" << test_case << " ";
        memset(graph, -1, sizeof(graph));
        memset(visited, 0, sizeof(visited));
        check = 0;
        for (int i = 0; i < road_no; i++) {
            cin >> from >> to;
            if (graph[from][0] == -1) graph[from][0] = to;
            else graph[from][1] = to;
        }
        visited[0] = 1;
        dfs(0);
        cout << check << endl;
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}