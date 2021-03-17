#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    vector<bool> check(lost.size(), false);

    // 여벌 체육복을 가져온 학생이 체육복을 도난당했다면 reserve에서 제외
    // 이 학생들은 체육복을 빌려줄 수는 없지만 체육수업을 들을 수 있다
    for (int i = 0; i < lost.size(); i++) {
        auto res = find(reserve.begin(), reserve.end(), lost[i]);
        if (res != reserve.end()) {
            reserve.erase(res);
            check[i] = true;
            answer++;
        }
    }

    for (int i = 0; i < lost.size() && !reserve.empty(); i++) {
        if (!check[i]) {
            for (int j = 0; j < reserve.size(); j++) {
                // 바로 앞번호의 학생이나 바로 뒷번호의 학생이 있는지 확인
                if (reserve[j] == lost[i] - 1 || reserve[j] == lost[i] + 1) {
                    reserve.erase(reserve.begin() + j);
                    answer++;
                    break;
                }
            }
        }
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 5;
    vector<int> lost = { 1, 2 };
    vector<int> reserve = { 2, 3 };
    cout << solution(n, lost, reserve);
    return 0;
}