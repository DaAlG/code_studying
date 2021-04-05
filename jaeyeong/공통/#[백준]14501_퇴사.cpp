//메모지에이션 결과가 순차대로 나와야 한다는 고정관념을 버리자
//목표는 모든 날을 통틀어 최대 페이니까 dp[n]에 원하던 답이 있진 않다.
using namespace std;
#include <iostream>

int main(int argc, const char* argv[]) {
    int n, result=0;
    int t[17], p[17];
    int dp[18] = {0};
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> p[i];
    }

    for (int i = 1; i <= n; i++) {
        //i번째 날에 일을 했을 경우
        if (i + t[i] <= n + 1) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
            result = max(result, dp[i + t[i]]);
        }
        //i번째 날에 일을 안했을 경우
        dp[i + 1] = max(dp[i + 1], dp[i]);
        result = max(result, dp[i + 1]);
    }

    cout << result << '\n';
}