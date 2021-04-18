#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool possible(vector<vector<int>> answer) {
    for (int i = 0; i < answer.size(); i++) {
        int x = answer[i][0];
        int y = answer[i][1];
        int stuff = answer[i][2];

        if (stuff) { // 보
            bool check = false;
            bool left = false;
            bool right = false;

            for (int j = 0; j < answer.size(); j++) {
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0) // 왼쪽 끝부분이 기둥 위
                    check = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y - 1 && answer[j][2] == 0) // 오른쪽 끝부분이 기둥 위
                    check = true;
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1) // 왼쪽 끝부분이 다른 보와 연결
                    left = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y && answer[j][2] == 1) // 오른쪽 끝부분이 다른 보와 연결
                    right = true;
            }

            // 양쪽 끝부분이 다른 보와 동시에 연결되어있으면 설치 가능 
            if (left && right) check = true;
            
            // 아니라면 거짓 반환
            if (!check) return false;
        }
        else { // 기둥
            bool check = false;
            if (y == 0) check = true; // 바닥 위
            
            for (int j = 0; j < answer.size(); j++) {
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1) // 보의 오른쪽 끝 부분 위
                    check = true;
                if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == 1) // 보의 왼쪽 끝 부분 위
                    check = true;
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0) // 다른 기둥 위
                    check = true;
            }

            // 아니라면 거짓 반환
            if (!check) return false;
        }
    }
    return true;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;

    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int stuff = build_frame[i][2];
        int operate = build_frame[i][3];

        if (operate) { // 설치
            // 일단 설치를 해본다
            answer.push_back({ x, y, stuff });
            // 가능한 구조물인지 확인
            if (!possible(answer)) {
                // 가능한 구조물이 아니라면 다시 제거
                answer.pop_back();
            }
        }
        else { // 삭제
            // 일단 삭제를 해본다
            int index = 0;
            for (int j = 0; j < answer.size(); j++) {
                if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == stuff) {
                    index = j;
                }
            }

            vector<int> erased = answer[index];
            answer.erase(answer.begin() + index);
            // 가능한 구조물인지 확인
            if (!possible(answer)) {
                // 가능한 구조물이 아니라면 다시 설치
                answer.push_back(erased);
            }
        }
    }

    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    int n = 5;
    vector<vector<int>> build_frame = { { 1, 0, 0, 1}, {1, 1, 1, 1}, {2, 1, 0, 1}, {2, 2, 1, 1}, {5, 0, 0, 1}, {4, 1, 0, 1}, {4, 2, 1, 1}, {3, 2, 1, 1} };
    vector<vector<int>> answer = solution(n, build_frame);
    
    for (int i = 0; i < answer.size(); i++) {
        for (int j = 0; j < answer[i].size() - 1; j++)
            cout << answer[i][j] << ", ";
        cout << answer[i].back() << '\n';
    }

    return 0;
}