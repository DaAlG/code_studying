#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> graph;
int n, m; //m은 단어의 길이
int visit[52];

bool is_neighbor(string a, string b) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] != b[i]) cnt++;
        if (cnt == 2) return false;
    }
    return true;
}

void bfs(int s, int f, int depth) {
    queue<int> q;
    q.push(s);
    visit[s] = 1;
    while (!q.empty()) {
        int c = q.back();
        if (c == f) break;
        q.pop();
        for (int i = 0; i < graph[c].size(); i++) {
            if (!visit[graph[c][i]]) {
                visit[graph[c][i]] = visit[c] + 1;
                q.push(graph[c][i]);
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int t=0;
    vector<int> v;

    n = words.size();
    m = words[0].size();

    for (int i = 0; i <= n; i++)
        graph.push_back(v);
    for (int i = 0; i < n; i++) {
        if (target == words[i]) break;
        if (i == n - 1) return answer;
    }
    for (int i = 0; i < n; i++) {
        string a = words[i], b;
        if (a == target)
            t = i;
        for (int j = i + 1; j < n; j++) {
            b = words[j];
            if (is_neighbor(a, b) == true) {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (is_neighbor(words[i], begin) == true) {
            graph[n].push_back(i);
            graph[i].push_back(n);
        }
    }
    bfs(n, t, 1);
    return answer = visit[t]-1;
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = { "hot", "dot", "dog", "lot", "log" };
    cout<<solution(begin, target, words);
}