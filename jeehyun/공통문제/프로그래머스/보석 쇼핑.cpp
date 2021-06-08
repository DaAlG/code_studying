#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer(2);
    map<string, int> mp;
    set<string> st;

    for (int i = 0; i < gems.size(); i++) {
        st.insert(gems[i]);
    }


    int n = st.size(); // 보석 종류
    int minLen = 100001; // 가장 짧은 구간 길이
    int left = 0; // 시작 위치
    int right = 0; // 끝 위치

    mp[gems[right]]++;

    while (left <= right && right < gems.size()) {
        if (mp.size() == n) { // 모든 종류의 보석 포함
            // 더 짧은 구간이라면 갱신
            if (right - left < minLen) {
                answer[0] = left + 1;
                answer[1] = right + 1;
                minLen = right - left;
            }

            // 시작 위치 이동
            mp[gems[left]]--;
            
            // 보석 개수가 0이면 빼기 
            if (mp[gems[left]] == 0)
                mp.erase(gems[left]);
            left++;
            continue;
        }

        // 가장 짧은 구간을 찾았다면 종료
        if (right == gems.size() - 1)
            break;

        // 끝 위치 이동
        right++;
        mp[gems[right]]++;
    }

    return answer;
}