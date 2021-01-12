// SW Expert Academy
// S/W 문제해결 기본 1일차 - 1206 View

#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T = 10;
    const int MAX = 1000;
    int len;
    int arr[MAX];

    for (test_case = 1; test_case <= T; ++test_case)
    {
        cin >> len;
        memset(arr, 0, sizeof(arr));

        int h;
        int solution = 0;
        for (int i = 0; i < len; i++) {
            cin >> arr[i];
        }

        for (int i = 2; i < len - 2; i++) {
            if ((h = arr[i] - max(max(arr[i - 1], arr[i + 1]), max(arr[i - 2], arr[i + 2]))) > 0)
                solution += h;
        }

        cout << "#" << test_case << " " << solution << endl;
    }

    return 0;
}