#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool valid(vector<string>& room) {
    int n = 5;

    vector<vector<int>> inUse(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (room[i][j] == 'P') {
                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < 0 || ni >= n || nj < 0 || nj >= n) continue;

                    switch (room[ni][nj]) {
                    case 'P':
                        return false;
                    case 'O':
                        if (inUse[ni][nj])
                            return false;
                        inUse[ni][nj] = true;
                        break;
                    }
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer(places.size());

    for (int i = 0; i < places.size(); i++) {
        vector<string> room = places[i];
        answer[i] = valid(places[i]);
    }

    return answer;
}