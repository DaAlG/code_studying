#include <iostream>
#include <queue>

using namespace std;

int main(int argc, char** argv)
{
    int k, T = 10;
    queue<int> q;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;

        for (int i = 0; i < 8; i++) {
            cin >> k;
            q.push(k);
        }

        int cycle = 1;
        while (1) {
            int now = q.front() - cycle;
            q.pop();
            
            // 0보다 작아지거나 0일 경우 0 저장하고 종료
            if (now <= 0) {
                q.push(0);
                break;
            }
            q.push(now);
            cycle++;

            // 사이클이 끝나면 다시 1부터 시작
            if (cycle > 5)
                cycle = 1;
        }

        cout << "#" << test_case << " ";

        // 암호 출력
        while (!q.empty()) {
            cout << q.front() << " ";
            q.pop();
        }
        cout << "\n";
    }
    return 0;
}