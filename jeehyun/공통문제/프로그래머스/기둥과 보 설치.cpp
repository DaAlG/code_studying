#include <string>
#include <vector>
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
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0) // 한쪽 끝부분이 기둥 위
                    check = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y - 1 && answer[j][2] == 0)
                    check = true;
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1)
                    left = true;
                if (answer[j][0] == x + 1 && answer[j][1] == y && answer[j][2] == 1)
                    right = true;
            }

            if (left && right) check = true;
            if (!check) return false;
        }
        else { // 기둥
            bool check = false;
            if (y == 0) check = true; // 바닥 위
            
            for (int j = 0; j < answer.size(); j++) {
                if (answer[j][0] == x - 1 && answer[j][1] == y && answer[j][2] == 1) // 보의 한 쪽 끝 부분 위
                    check = true;
                if (answer[j][0] == x && answer[j][1] == y && answer[j][2] == 1) // 보의 한 쪽 끝 부분 위
                    check = true;
                if (answer[j][0] == x && answer[j][1] == y - 1 && answer[j][2] == 0) // 다른 기둥 위
                    check = true;
            }

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
            if (b) { // 설치
                if ((building[x][y - 1] == !a || building[x + 1][y - 1] == !a) || (building[x - 1][y] == a && building[x + 1][y] == a)) {
                    building[x][y] = a;
                }
            }
            /*else { // 삭제
                if (building[x + 1][y - 1] == !a || building[])
            }*/
        }
        else { // 삭제
            if (b) { // 설치
                if (y == 0 || building[x][y - 1] == a || building[x - 1][y] == !a) {
                    building[x][y] = a;
                }
            }
            /*else { // 삭제
                if (building[x][y] == -1) {
                    building[x][y-1] = -1;

                }
            }*/
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (building[i][j] != -1) {
                cout << i << ", " << j << ", " << building[i][j] << '\n';
                answer.push_back({ i, j, building[i][j] });
            }
        }
    }

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