#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

int arr[MAX];
int dp[MAX];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
        for (int j = 0; j < i; j++) {
            // 마지막 원소에서 감소하는 부분 수열의 원소를 추가해주어야 해서 dp[j] + 1
            if (arr[j] > arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }

        // 가장 긴 감소하는 부분 수열
        answer = max(answer, dp[i]);
    }
    cout << n - answer;

    return 0;
}