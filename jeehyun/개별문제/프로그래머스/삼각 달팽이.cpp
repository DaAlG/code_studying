#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    int max = (n * (n + 1)) / 2;
    vector<int> answer(max);

    int len = n;
    int cnt = 0;
    int k = 1;
    int cur = 0;

    while (len > 0) {
        cur += 2 * cnt;
        for (int i = 1; i <= len && k <= max; i++) {
            answer[cur] = k;
            cur += 2 * cnt + i;
            k++;
        }

        len--;
        cur -= (n - cnt);
        for (int i = 0; i < len && k <= max; i++) {
            answer[++cur] = k;
            k++;
        }

        len--;
        for (int i = 0; i < len && k <= max; i++) {
            cur -= (n - cnt) - i;
            answer[cur] = k;
            k++;
        }
        len--;
        cnt++;
    }

    return answer;
}

int main()
{
    int n = 6;
    vector<int> answer = solution(n);

    for (int k : answer) {
        cout << k << ' ';
    }
    return 0;
}