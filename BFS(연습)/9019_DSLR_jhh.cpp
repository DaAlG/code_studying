/*
네 자리 숫자 A와B가 주어졌을 때
a->b로 바꾸는 최소 연산 횟수

=> 연산이 무엇인지 알아야 함

D: N ->2*N
S: N->n-1
L: 한자리 씩 왼쪽으로
R: 한 자리씩 오른쪽으로

네자리수 -> 10000개 많은 정점을 나타내는 것이 아니기 떄문에 bfs 가능
최소 연산 횟수 + 어떻게 해서 그 최소가 나왔는지 보여야 함
how[i]=i 는 어떻게 만들었는지

방법의 길이가 얼마나 큰지 예상할 수 없게 됨
D라는 답을 구했을 때 역추적 할 때는 전체의 과정을 역추적이아니라 한단계 한다음에 역추적해야 함
*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
bool check[10001];
int dist[10001];
char how[10001];
int from[10001];
void print(int n, int m) {
    if (n == m) return;
    print(n, from[m]);
    cout << how[m];
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        memset(check, false, sizeof(check));
        memset(dist, 0, sizeof(dist));
        memset(how, 0, sizeof(how));
        memset(from, 0, sizeof(from));
        check[n] = true;
        dist[n] = 0;
        from[n] = -1;
        queue<int> q;
        q.push(n);
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            int next = (now * 2) % 10000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'D';
            }
            next = now - 1;
            if (next == -1) next = 9999;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'S';
            }
            next = (now % 1000) * 10 + now / 1000; 
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'L';
            }
            next = (now / 10) + (now % 10) * 1000;
            if (check[next] == false) {
                q.push(next);
                check[next] = true;
                dist[next] = dist[now] + 1;
                from[next] = now;
                how[next] = 'R';
            }
        }
        print(n, m);
        /*
        string ans = "";
        while (m != n) {
            ans += how[m];
            m = from[m];
        }
        reverse(ans.begin(), ans.end());
         */
        cout << '\n';
    }
    return 0;
}
