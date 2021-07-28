#include<iostream>
using namespace std;

char s[8][8];

int main(int argc, char** argv)
{
    int T = 10;
    int n = 8;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int len;
        cin >> len;

        for (int i = 0; i < n; i++) {
            cin >> s[i];
        }

        int answer = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= n - len; j++) {
                int f, e;

                for (f = j, e = j + len - 1; f < e; f++, e--) {
                    if (s[i][f] != s[i][e])
                        break;
                }
                if (f >= e) answer++;

                for (f = j, e = j + len - 1; f < e; f++, e--) {
                    if (s[f][i] != s[e][i]) {
                        break;
                    }
                }
                if (f >= e) answer++;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}