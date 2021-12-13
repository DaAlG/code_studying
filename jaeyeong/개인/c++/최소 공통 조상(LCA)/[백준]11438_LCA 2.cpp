// ������������.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
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
    if (dep[b] < dep[a]) tmp = a, a = b, b = tmp; // b�� depth �� �� ���
    tmp = dep[b] - dep[a];
    for (int i = 0; i < PIV; i++)
    {
        int bit = (1 << i);
        if ((tmp & bit) == bit)
            b = par[i][b];
    }
    if (b == a) return a; // a �� �ٷ� lca �̹Ƿ� ����

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
    // k�� n�� ���� ���� mod �� ���� ������
    // 21 = 10101(2)
    int ret = 1;
    int seven[100];
    seven[0] = 7;
    for (int i = 1; i < 10; i++)
        seven[i] = (seven[i - 1] * seven[i - 1]) % mod;
    // seven[i] : 7�� 2��i������ �� (�� mod������)
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
                par[0][next] = val; // �θ� ����
                que.push(next);
                que.push(depth + 1);
            }
        }
    }
    //par[0][j] : 1����, par[1][j] : 2����, par[2][j] : 4����... 
    for (int i = 1; i < PIV; i++)
        for (int j = 1; j <= N; j++)
            par[i][j] = par[i - 1][par[i - 1][j]]; // ���� 2^i��° ���� == ��  2^(i-1) ��° ������ 2^(i-1) ��° ����

    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", lca(a, b));
    }
    return 0;
}

