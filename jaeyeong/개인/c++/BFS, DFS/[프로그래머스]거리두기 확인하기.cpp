#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int direction[4][2] = { {0,1},{0,-1},{1,0},{-1,0} };
bool visit[5][5] = { false };

bool inRange(int x, int y) {
    return 0 <= x && x < 5 && 0 <= y && y < 5;
}
bool dfs(int x, int y, int cnt, vector<string> room) {
    bool res = true;
    visit[x][y] = true;
    if (cnt == 2) {
        if (room[x][y] == 'P') return false;
        else return true;
    }
    for (int i = 0; i < 4; i++) {
        int nx = x + direction[i][0];
        int ny = y + direction[i][1];
        if (!inRange(nx, ny) || visit[nx][ny] || room[nx][ny]=='X') continue;
        if (room[nx][ny] == 'P') return false;
        res *= dfs(nx, ny, cnt + 1, room);
    }
    return res;
}

int checkRoom(vector<string> room) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (room[i][j] == 'P' && !dfs(i, j, 0, room)) return 0;
            memset(visit, false, sizeof(visit));
        }
    }
    return 1;
}
vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (int i = 0; i < 5; i++) {
        int res = checkRoom(places[i]);
        answer.push_back(res);
    }
    return answer;
}

int main() {
    vector<vector<string>> places = { {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"},
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"},
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"},
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"},
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"} };
    vector<int> answer = solution(places);
    for (int i = 0; i < 5; i++)
        cout << answer[i] << ' ';
    
}