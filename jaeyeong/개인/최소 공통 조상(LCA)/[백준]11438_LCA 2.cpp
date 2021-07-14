// 최저공통조상.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//
#include <stdio.h>
#include <vector>
#include <queue>
#define MAX 100005
#define PIV 17
using namespace std;
vector<int> con[MAX];
int dep[MAX];
int par[PIV][MAX];
int lca(int a, int b)
{
    int tmp;
    if (dep[b] < dep[a]) tmp = a, a = b, b = tmp; // b의 depth 가 더 깊게
    tmp = dep[b] - dep[a];
    for (int i = 0; i < PIV; i++)
    {
        int bit = (1 << i);
        if ((tmp & bit) == bit)
            b = par[i][b];
    }
    if (b == a) return a; // a 가 바로 lca 이므로 리턴

    for (int i = PIV - 1; i >= 0; i--)
    {
        if (par[i][a] != par[i][b])
            a = par[i][a], b = par[i][b];
    }
    return par[0][a];
}
int main()
{
    /*
    int n = 21;
    int k = 7;
    int mod = 11;
    // k를 n번 곱한 수의 mod 로 나눈 나머지
    // 21 = 10101(2)
    int ret = 1;
    int seven[100];
    seven[0] = 7;
    for (int i = 1; i < 10; i++)
        seven[i] = (seven[i - 1] * seven[i - 1]) % mod;
    // seven[i] : 7을 2의i제곱한 값 (의 mod나머지)
    int val = 1;
    for (int bit = 0; bit <= 10; bit++)
    {
        //int val = (1 << bit);
        if ((n & val) == val)
            ret = (ret * seven[bit]) % mod;
        val *= 2;
    }
    printf("%d\n", ret);
    return 0;
    */

    int M, N, a, b;
    scanf("%d", &N);
    for (int i = 1; i <= N - 1; i++)
    {
        scanf("%d %d", &a, &b);
        con[a].push_back(b);
        con[b].push_back(a);
        dep[i] = 0;
    }
    queue<int> que;
    que.push(1); // value
    que.push(1); // depth
    int depth = 0;
    while (que.empty() == false)
    {
        int val = que.front(); que.pop();
        depth = que.front(); que.pop();
        dep[val] = depth;
        for (int next : con[val])
        {
            if (dep[next] == 0)
            {
                par[0][next] = val; // 부모를 저장
                que.push(next);
                que.push(depth + 1);
            }
        }
    }
    //par[0][j] : 1조상, par[1][j] : 2조상, par[2][j] : 4조상... 
    for (int i = 1; i < PIV; i++)
        for (int j = 1; j <= N; j++)
            par[i][j] = par[i - 1][par[i - 1][j]]; // 나의 2^i번째 조상 == 내  2^(i-1) 번째 조상의 2^(i-1) 번째 조상

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}

