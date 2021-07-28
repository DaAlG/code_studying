#include<iostream>
using namespace std;

int power(int n, int k) {
    if (k == 0) return 1;
    return n * power(n, k - 1);
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;
        int n, k;
        cin >> n >> k;
        cout << "#" << test_case << " " << power(n, k) << "\n";
    }
    return 0;
}