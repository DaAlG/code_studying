#include <string>
#include <vector>

using namespace std;

int arr[1000][1000];
int dir[3][2] = { {1,-1}, {0,1}, {-1,0} };

vector<int> solution(int n) {
    vector<int> answer;
    int nx = 0, ny = n-1;
    int c = 1, d = 0, lim = 0;
    for (int i = 1; i <= n; i++)
        lim += i;

    while (c <= lim) {
        arr[nx][ny] = c++;
        //������ȯ�� �ʿ��Ҷ�: ���̻� �� �� �ִ°����� �ƴҶ�, nx,ny�� 0�� �ƴ� ��
        if ((0 <= nx + dir[d][0] && nx + dir[d][0] < n) &&
            (0 <= ny + dir[d][1] && ny + dir[d][1] < n)) {
            if (arr[nx + dir[d][0]][ny + dir[d][1]] == 0) {
                nx += dir[d][0];
                ny += dir[d][1];
                continue;
            }
        }
        //���� ��ȯ
        d++;
        if (d == 3) d = 0;
        nx += dir[d][0];
        ny += dir[d][1];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] != 0)
                answer.push_back(arr[i][j]);
        }
    }
    return answer;
}

int main() {
    int n = 4;
    solution(n);
}