#include<iostream>
using namespace std;
int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;

        int answer = 1;
        for (int i = 1; i <= n; i++) {
            char ch;
            cin >> i >> ch;

            if (i <= n / 2) {
                int left, right;
                if (i == n / 2 && n % 2 == 0) cin >> left;
                else cin >> left >> right;

                if (ch >= '0' && ch <= '9') answer = 0;
            }
            else {
                if (!(ch >= '0' && ch <= '9')) answer = 0;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}