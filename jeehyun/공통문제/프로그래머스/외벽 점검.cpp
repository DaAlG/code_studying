#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    // 길이를 2배로 늘려서 원형을 일자 형태로 변경
    int len = weak.size();
    for (int i = 0; i < len; i++) {
        weak.push_back(weak[i] + n);
    }

    // 투입할 친구 수의 최솟값을 찾아야 하므로 dist.size() + 1로 초기화
    int answer = dist.size() + 1;

    // 0부터 len - 1까지의 위치를 각각 시작점으로 설정
    for (int start = 0; start < len; start++) {
        do {
            int cnt = 1; // 투입할 친구 수

            // 해당 친구가 점검할 수 있는 마지막 위치
            int pos = weak[start] + dist[cnt - 1]; 

            // 시작점부터 모든 취약한 지점을 확인
            for (int idx = start; idx < start + len; idx++) {
                // 점검할 수 있는 위치를 벗어나는 경우
                if (pos < weak[idx]) {
                    cnt++; // 새로운 친구를 투입
                    if (cnt > dist.size()) // 더 투입이 불가능하다면 종료
                        break;
                    pos = weak[idx] + dist[cnt - 1];
                }
            }
            answer = min(answer, cnt); // 최솟값 계산
        } while (next_permutation(dist.begin(), dist.end()));
    }

    if (answer > dist.size())
        return -1;
    return answer;
}