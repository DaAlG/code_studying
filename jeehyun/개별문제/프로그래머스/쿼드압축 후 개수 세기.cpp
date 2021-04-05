#include <string>
#include <vector>

using namespace std;

int zero = 0;
int one = 0;

void dfs(const vector<vector<int>>& arr, int x, int y, int size) {
    int num = arr[x][y];
    bool check = true;

    for (int i = x; check && i < x + size; i++) {
        for (int j = y; check && j < y + size; j++) {
            if (arr[i][j] != num) {
                check = false;
                break;
            }
        }
    }

    if (!check) { // S 내부에 있는 모든 수가 같은 값이 아니면 4개로 나눈 뒤 같은 방식으로 압축
        size /= 2;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                dfs(arr, x + i * size, y + j * size, size);
            }
        }
    }
    else { // S 내부에 있는 모든 수가 같은 값일 경우 종료
        if (num) one++;
        else zero++;
    }
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;

    dfs(arr, 0, 0, arr.size());
    answer.push_back(zero);
    answer.push_back(one);

    return answer;
}