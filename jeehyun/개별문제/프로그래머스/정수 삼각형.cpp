#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    dp[0][0] = triangle[0][0];
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            // 대각선 왼쪽 칸으로 이동
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            // 대각선 오른쪽 칸으로 이동 
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }

    // 가장 아래 칸의 최댓값
    return *max_element(dp[n - 1].begin(), dp[n - 1].end());
}