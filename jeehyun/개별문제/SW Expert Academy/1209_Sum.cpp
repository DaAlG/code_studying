#include<iostream>

using namespace std;

int arr[101][101];

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;

        for (int i = 0; i < 100; i++) {
            arr[100][i] = arr[i][100] = 0;
        }

        int diag = 0;
        int diag2 = 0;
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                cin >> arr[i][j];
                if (i == j) diag += arr[i][j];
                if (i + j == 99) diag2 += arr[i][j];
                arr[i][100] += arr[i][j];
                arr[100][j] += arr[i][j];
            }
        }

        int answer = max(diag, diag2);
        for (int i = 0; i < 100; i++) {
            answer = max(answer, max(arr[i][100], arr[100][i]));
        }
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0;
}