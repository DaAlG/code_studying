#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool possible(vector<int>& stones, int m, int k) {
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++) {
        // 디딤돌에 적힌 숫자가 m보다 작거나 같으면 0이라서 밟을 수 없음
        if (stones[i] <= m) cnt++;
        else cnt = 0;

        // 건너뛰어야 하는 칸이 k 이상이면 m번째 친구는 징검다리를 건너지 못한다
        if (cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;

    int left = 0;
    int right = *max_element(stones.begin(), stones.end());

    // 이분 탐색
    while (left <= right) {
        int mid = (left + right) / 2;

        // mid번째 친구가 디딤돌을 모두 건널 수 있으면 mid + 1 ~ right에서 최댓값을 찾는다
        if (possible(stones, mid, k)) {
            left = mid + 1;    
        }
        else { // mid번재 친구가 디딤돌을 모두 건널 수 없는 경우 0 ~ mid - 1에서 최댓값을 찾는다 
            answer = mid;
            right = mid - 1;
        }
    }

    return answer;
}