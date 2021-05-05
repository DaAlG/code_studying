#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rotate(vector<vector<int>>& key) {
    int n = key.size();
    int m = key[0].size();
    vector<vector<int>> res(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][n - i - 1] = key[i][j];
        }
    }
    return res;
}

bool unlock(vector<vector<int>>& lock) {
    int n = lock.size() / 3;

    // 자물쇠의 중간 부분이 모두 1인지 확인
    for (int i = n; i < 2 * n; i++) {
        for (int j = n; j < 2 * n; j++) {
            if (lock[i][j] != 1)
                return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int n = lock.size();
    int m = key.size();

    vector<vector<int>> new_lock(n * 3, vector<int>(n * 3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            new_lock[i + n][j + n] = lock[i][j];
        }
    }

    for (int rot = 0; rot < 4; rot++) {
        // 열쇠 회전
        key = rotate(key);

        for (int x = 0; x < n * 2; x++) {
            for (int y = 0; y < n * 2; y++) {
                // 자물쇠와 열쇠를 더한다
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] += key[i][j];
                    }
                }

                // 자물쇠에 열쇠가 정확히 들어맞는지 검사
                if (unlock(new_lock)) {
                    return true;
                }

                // 자물쇠를 원래대로 되돌린다
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        new_lock[x + i][y + j] -= key[i][j];
                    }
                }
            }
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> key = { { 0, 0, 0}, {1, 0, 0}, {0, 1, 1} };
    vector<vector<int>> lock = { { 1, 1, 1 }, {1, 1, 0}, {1, 0, 1} };
    cout << solution(key, lock);
}