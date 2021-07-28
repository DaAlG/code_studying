#include<iostream>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int T = 10;

    for (int test_case = 1; test_case <= T; ++test_case) {
        int n;
        cin >> n;

        vector<int> b(n);
        for (int i = 0; i < n; i++) cin >> b[i];

        int answer = 0;
        for (int i = 2; i < n - 2; i++) {
            bool check = true;
            int view = 255;
            for (int j = -2; j <= 2; j++) {
                if (j == 0) continue;
                if (b[i + j] > b[i]) {
                    check = false;
                    break;
                }
                view = min(view, b[i] - b[i + j]);
            }

            if (check) {
                answer += view;
            }
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}