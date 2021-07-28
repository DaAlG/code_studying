#include <iostream>
#include <algorithm>
using namespace std;

int cnt[101];

int main()
{
    int T, k;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;
        cout << "#" << test_case << " ";

        fill_n(cnt, 101, 0);

        for (int i = 0; i < 1000; i++) {
            cin >> k;
            cnt[k]++;
        }

        int answer = 0;
        int maxCnt = 0;

        for (int i = 0; i <= 100; i++) {
            if (cnt[i] >= maxCnt) {
                answer = i;
                maxCnt = cnt[i];
            }
        }
        cout << answer << "\n";
    }
    return 0;
}