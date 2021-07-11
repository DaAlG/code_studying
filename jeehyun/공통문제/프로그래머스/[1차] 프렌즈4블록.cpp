#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int, int>> possible(int m, int n, vector<string>& board) {
    vector<pair<int, int>> blocks;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] != '0') {
                char ch = board[i][j];
                if (i + 1 < m && j + 1 < n) {
                    // 같은 모양의 블록이 4개 붙어있는지 확인
                    if (board[i + 1][j] == ch && board[i][j + 1] == ch && board[i + 1][j + 1] == ch) {
                        blocks.push_back({ i, j });
                        blocks.push_back({ i, j + 1 });
                        blocks.push_back({ i + 1, j });
                        blocks.push_back({ i + 1, j + 1 });
                    }
                }
            }
        }
    }

    // 정렬 후 중복 제거
    sort(blocks.begin(), blocks.end());
    blocks.erase(unique(blocks.begin(), blocks.end()), blocks.end());
    
    return blocks;
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;

    while (1) {
        vector<pair<int, int>> blocks = possible(m, n, board);

        // 지울 블록이 없으면 종료
        if (blocks.empty())
            break;

        answer += blocks.size();
        for (int i = 0; i < blocks.size(); i++) {
            // 지운 블록은 0으로 표시해준다
            board[blocks[i].first][blocks[i].second] = '0';
        }
        blocks.clear();

        // 블록이 지워진 후에는 위에 있는 블록이 아래로 떨여져 빈 공간을 채운다
        for (int i = m - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                int now = i;
                while (now + 1 < m && board[now + 1][j] == '0') {
                    swap(board[now + 1][j], board[now][j]);
                    now++;
                }
            }
        }
    }

    return answer;
}