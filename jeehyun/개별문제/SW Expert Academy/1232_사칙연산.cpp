#include<iostream>

using namespace std;

int n;
int tree[1001][3]; // 연산자 or 숫자, left, right

int calc(int v) {
    if (tree[v][0] < 0) {
        int a = calc(tree[v][1]);
        int b = calc(tree[v][2]);
        if (tree[v][0] == -1) return a + b;
        else if (tree[v][0] == -2) return a - b;
        else if (tree[v][0] == -3) return a * b;
        else if (tree[v][0] == -4) return a / b;
    }
    return tree[v][0];
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            char ch;
            scanf("%d %c", &i, &ch);
            if (ch >= '0' && ch <= '9') {
                tree[i][0] = 0;
                while (ch >= '0' && ch <= '9') {
                    tree[i][0] = tree[i][0] * 10 + ch - '0';
                    ch = getchar();
                }
            }
            else {
                if (ch == '+') tree[i][0] = -1;
                else if (ch == '-') tree[i][0] = -2;
                else if (ch == '*') tree[i][0] = -3;
                else if (ch == '/') tree[i][0] = -4;
                scanf("%d %d", &tree[i][1], &tree[i][2]);
            }
        }
        cout << "#" << test_case << " " << calc(1) << "\n";
    }
    return 0;
}