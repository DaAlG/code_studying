#include <iostream>
#include <string>
#include <vector>

using namespace std;
long long MOD = 1e7 + 19;
vector<vector<long long>> arr;

//nCr
long long comb(int n, int r) {
    if (n < r) return 0;
    long long& ret = arr[n][r];
    if (ret != -1) return ret;

    if (n == r || r == 0) return ret = 1;
    return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
}

int solution(vector<vector<int>> a) {
    int answer = -1;
    int row = a.size();
    int col = a[0].size();
    arr = vector<vector<long long>>(301, vector<long long>(301, -1));

    vector<int> a_colNum(col + 1, 0);
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            a_colNum[j + 1] += a[i][j];


    //dp[column][num] = a[0~row][0~column]���� 1,2�� ������ �����ϸ鼭 num���� ���� ¦���� �迭�� ���� �� �ִ� ����� ��
    vector<vector<long long> > dp(col + 1, vector<long long>((row + 1), 0));
    dp[1][row - a_colNum[1]] = comb(row, a_colNum[1]);
    for (int c = 1; c <= col; c++) {
        int colNum = a_colNum[c];
        for (int num = 0; num <= row; num++) {
            for (int k = 0; k <= colNum; k++) {
                int willSetOddRow = colNum - k;
                // 1�� �����ϰ� �� �� 1�� ¦���� ���� ���� ���� = ¦���� �� 1�� �������� �ʴ� �� + Ȧ���� �� 1�� �����ϴ� ��
                int willBeEvenRowCnt = (num - k) + willSetOddRow;
                if (willSetOddRow < 0 || willBeEvenRowCnt > row || willBeEvenRowCnt < 0) continue; // IMPOSSIBLE

                // ����� �� = ¦���࿡ 1�� �����ϴ� ����� �� * Ȧ���࿡ 1�� �����ϴ� ����� �� % MOD
                long long numOfCase = (comb(num, k) * comb(row - num, colNum - k)) % MOD;
                dp[c][willBeEvenRowCnt] += dp[c - 1][num] * numOfCase % MOD;
                dp[c][willBeEvenRowCnt] %= MOD;
            }

        }
    }

    return answer = dp[col][row];
}

int main() {
    vector<vector<int>> a = { {0,1,0}, {1,1,1}, {1,1,0}, {0,1,1} };
    cout << solution(a) << '\n';
}