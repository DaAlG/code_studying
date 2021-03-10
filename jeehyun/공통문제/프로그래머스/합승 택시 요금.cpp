#include <iostream>
#include <string>
#include <vector>
#define MAX 201
#define INF 10000000
using namespace std;

int d[MAX][MAX]; // 두 지점 사이의 택시요금

int solution(int n, int s, int a, int b, vector<vector<int>> fares) 
{
    // d 배열 초기화
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                d[i][j] = INF;
        }
    }

    // 두 지점 사이의 택시요금 저장
    for (int i = 0; i < fares.size(); i++) {
        int u = fares[i][0];
        int v = fares[i][1];
        int c = fares[i][2];

        d[u][v] = c;
        d[v][u] = c;
    }

    // 각 지점간의 최소 택시요금 계산
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][j] > d[i][k] + d[k][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    int answer = INF;

    // 최저 택시요금 계산
    for (int k = 1; k <= n; k++) {
        answer = min(answer, d[s][k] + d[k][a] + d[k][b]);
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 6;
    int s = 4;
    int a = 5;
    int b = 6;

    vector<vector<int>> fares = { {2,6,6}, {6,3,7}, {4,6,7}, {6,5,11}, {2,5,12}, {5,3,20}, {2,4,8}, {4,3,9} };

    cout << solution(n, s, a, b, fares);
    return 0;
}