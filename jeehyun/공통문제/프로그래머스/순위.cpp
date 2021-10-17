#include <string>
#include <vector>
#define INF 987654321
using namespace std;

int solution(int n, vector<vector<int>> results) {
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
    for (auto res : results) {
        d[res[0]][res[1]] = 1;
    }

    // floyd-warshall로 모든 정점에서 모든 정점으로의 거리 구하기
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }

    int answer = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            // 둘 중 하나라도 INF가 아니라면 순위를 알 수 있다는 의미
            if (d[i][j] != INF || d[j][i] != INF) 
                cnt++;
        }
        // 자신을 제외한 다른 모든 학생의 경우 순위를 알 수 있으면 자신의 순위를 알 수 있음
        if (cnt == n - 1)
            answer++;
    }

    return answer;
}