//�޸������̼� ����� ������� ���;� �Ѵٴ� ���������� ������
//��ǥ�� ��� ���� ��Ʋ�� �ִ� ���̴ϱ� dp[n]�� ���ϴ� ���� ���� �ʴ�.
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
        //i��° ���� ���� ���� ���
        if (i + t[i] <= n + 1) {
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + p[i]);
            result = max(result, dp[i + t[i]]);
        }
        //i��° ���� ���� ������ ���
        dp[i + 1] = max(dp[i + 1], dp[i]);
        result = max(result, dp[i + 1]);
    }

    cout << result << '\n';
}