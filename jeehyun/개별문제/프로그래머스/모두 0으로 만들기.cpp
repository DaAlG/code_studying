#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define MAX 300001

using namespace std;

vector<long long> ll_a;
vector<int> e[MAX];

long long dfs(int p, int now) {
    long long sum = 0;
    for (int next : e[now]) {
        if (next != p) {
            sum += dfs(now, next);
        }
    }

    ll_a[p] += ll_a[now];
    sum += abs(ll_a[now]);

    return sum;
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    long long sum = 0;
    for (int i = 0; i < a.size(); i++) {
        ll_a.push_back(a[i]);
        sum += a[i];
    }

    // 가중치 합이 0이 아닐 경우 모든 점들의 가중치를 0으로 만들 수 없음 
    if (sum != 0)
        return -1;

    long long answer = 0;
    // 트리 형성
    for (int i = 0; i < edges.size(); i++) {
        e[edges[i][0]].push_back(edges[i][1]);
        e[edges[i][1]].push_back(edges[i][0]);
    }
    answer += dfs(0, 0);
    return answer;
}

int main()
{
    vector<int> a = { -5, 0, 2, 1, 2 };
    vector<vector<int>> edges = { {0,1} ,{3,4},{2,3},{0,3 }};
    cout << solution(a, edges);
    return 0;
}