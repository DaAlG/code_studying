/*
 * BOJ 2775 부녀회장이 될테야
 */

#include <iostream>
#define MAX 15
#define endl "\n"
using namespace std;

int ap[MAX][MAX];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    for (int i = 0; i < MAX; i++) {
        for (int j = 1; j < MAX; j++) {
            if (i == 0) ap[i][j] = j;
            else ap[i][j] = ap[i][j - 1] + ap[i - 1][j];
        }
    }

    while (T--) {
        int k, n;
        cin >> k >> n;
        cout << ap[k][n] << endl;
    }
    return 0;
}
