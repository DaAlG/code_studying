#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;

    int diff[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    // 조이스틱을 위, 아래로 조작하는 횟수 계산
    for (auto ch : name)
        answer += diff[ch - 'A'];

    int len = name.length();
    int move = len - 1; // 오른쪽으로만 조작하는 횟수

    // 조이스틱을 좌우로 움직이는 최소 횟수 계산
    for (int i = 0; i < len; i++) {
        int next = i + 1;
        while (next < len && name[next] == 'A')
            next++;

        // 최소경로
        // 1. 원점에서 i번째를 먼저 갔다가, 원점을 지나 역주행하여 next번째에 도착
        // 2. 원점에서 역주행하여 next에 먼저 갔다가, 다시 원점으로 와서 i번째로 가는 경우
        // i는 원점에서 i로, len - next는 원점에서 역주행하여 next로 가는 횟수
        // min(i, len - next)에서 i는 다시 i로 돌아가는 횟수, len - next는 2의 경우에서 원점으로 돌아가는 횟수
        move = min(move, i + len - next + min(i, len - next));
    }
    answer += move;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string name = "ABAAAAAAAAABB";

    cout << solution(name);
}