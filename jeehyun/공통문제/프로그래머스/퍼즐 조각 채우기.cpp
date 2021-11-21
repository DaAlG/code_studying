#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#define cnt first
#define cells second
using namespace std;
typedef pair<int, int> pii;

int n;
bool visited[50][50];
vector<pii> block;
map<string, pii> blocks;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(vector<vector<int>>& board, int x, int y) {
    visited[x][y] = true;
    block.push_back({ x, y });

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= n || visited[nx][ny] || !board[nx][ny])
            continue;
        dfs(board, nx, ny);
    }
}

string makeString() {
    int minx = 50, maxx = 0;
    int miny = 50, maxy = 0;
    for (auto [x, y] : block) {
        minx = min(minx, x);
        maxx = max(maxx, x);
        miny = min(miny, y);
        maxy = max(maxy, y);
    }

    vector<vector<int>> arr(maxx - minx + 1, vector<int>(maxy - miny + 1));
    for (auto [x, y] : block) {
        arr[x - minx][y - miny] = 1;
    }

    string result = "";
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            result += to_string(arr[i][j]);
        }
        result += "n";
    }
    return result;
}

void rotate(vector<vector<int>>& board) {
    vector<vector<int>> nBoard(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            nBoard[j][n - i - 1] = board[i][j];
        }
    }
    board = nBoard;
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    n = game_board.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            game_board[i][j] = game_board[i][j] == 0 ? 1 : 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && game_board[i][j] == 1) {
                dfs(game_board, i, j);
                string s = makeString();
                blocks[s] = { blocks[s].first + 1, block.size() };
                block.clear();
            }
        }
    }

    int answer = 0;
    for (int r = 0; r < 4; r++) {
        rotate(table);
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && table[i][j] == 1) {
                    dfs(table, i, j);
                    string s = makeString();
                    if (blocks.count(s)) {
                        for (auto [x, y] : block) {
                            table[x][y] = 0;
                        }

                        answer += blocks[s].cells;
                        if (--blocks[s].cnt == 0)
                            blocks.erase(s);
                    }
                    block.clear();
                }
            }
        }
    }

    return answer;
}