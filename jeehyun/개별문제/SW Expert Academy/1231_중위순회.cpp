#include<iostream>
using namespace std;

int n;
char tree[101];

void inorder(int v) {
    if (v > n) return;

    inorder(2 * v);
    cout << tree[v];
    inorder(2 * v + 1);
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> i >> tree[i];

            int left, right;
            if (i < n / 2) {
                cin >> left >> right;
            }
            else if (i == n / 2) {
                cin >> left;
                if (n % 2)
                    cin >> right;
            }
        }

        cout << "#" << test_case << " ";
        inorder(1);
        cout << "\n";
    }
    return 0;
}