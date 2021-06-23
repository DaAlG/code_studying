#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int set[101];

struct Bridge {
    int u;
    int v;
    int c;
};

int getParent(int x) {
    if (set[x] == x) return x;
    else return set[x] = getParent(set[x]);
}

void unionParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    if (a < b) set[b] = a;
    else set[a] = b;
}

int findParent(int a, int b) {
    a = getParent(a);
    b = getParent(b);
    return a == b;
}

bool cmp(Bridge a, Bridge b) {
    return a.c < b.c;
}

int solution(int n, vector<vector<int>> costs) {
    // 자기 자신으로 초기화
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }

    vector<Bridge> bridges;
    for (int i = 0; i < costs.size(); i++) {
        bridges.push_back({ costs[i][0], costs[i][1], costs[i][2] });
    }
    
    // 오름차순으로 정렬
    sort(bridges.begin(), bridges.end(), cmp);

    int answer = 0;
    for (int i = 0; i < bridges.size(); i++) {
        // 사이클을 만들지 않는 경우 다리 건설
        if (!findParent(bridges[i].u, bridges[i].v)) {
            answer += bridges[i].c;
            unionParent(bridges[i].u, bridges[i].v);
        }
    }

    return answer;
}