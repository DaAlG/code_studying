#include <string>
#include <vector>
#include <algorithm>
#define MODULER 10000019

using namespace std;

void combination(vector<vector<long long>>& v, int r)
{
    v[0][0] = 1;
    for (int i = 1; i <= r; i++) {
        v[i][0] = 1;
        v[i][i] = 1;
        for (int j = 1; j < i; j++) {
            v[i][j] = (v[i - 1][j - 1] + v[i - 1][j]) % MODULER;
        }
    }
}

int solution(vector<vector<int>> a)
{
    int row = a.size();
    int col = a[0].size();

    // one[j] = j번째 열의 1의 개수
    vector<int> one(col + 1, 0);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            one[j] += a[i][j];
        }
    }

    vector<vector<long long>> ncr(row + 1, vector<long long>(row + 1, 0));
    combination(ncr, row);

    // dp[column][num] = arr[0~n][0~column]까지 num개의 행이 짝수인 경우의 수
    vector<vector<long long>> dp(col + 1, vector<long long>(row + 1, 0));
    dp[1][row - one[0]] = ncr[row][row - one[0]];

    for (int c = 1; c < col; c++) {
        int cnt = one[c]; // arr 배열에서 c열의 1의 개수
        for (int n = 0; n <= row; n++) { // 이때까지 세팅한 짝수행의 개수
            if (dp[c][n] == 0) continue;
            // 기존에 있던 행 중에 짝수개의 1을 가진 행에 1을 세팅하고자 하는 개수
            for (int k = 0; k <= cnt; k++) {
                if (n < k) continue;

                // 기존의 짝수행들 중 K개의 선택을 받지 못해서 짝수행 그대로 남아있는 경우
                // 기존의 홀수행들 중 1을 추가함으로써 짝수행이 되는 경우
                int even_row = n + cnt - (2 * k);
                if (even_row > row) continue;

                // 경우의 수 = (짝수행에 1을 세팅하는 경우의 수 * 홀수행에 1을 세팅하는 경우의 수) % MOD
                long long res = (ncr[n][k] * ncr[row - n][cnt - k]) % MODULER;
                dp[c + 1][even_row] = (dp[c + 1][even_row] + dp[c][n] * res) % MODULER;
            }
        }
    }

    return dp[col][row];
}