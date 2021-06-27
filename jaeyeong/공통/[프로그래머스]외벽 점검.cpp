#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
//1 2 3 4
int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0x3f3f3f3f;
    int w = weak.size();

    weak.resize(2 * w);
    for (int i = w; i < 2 * w; i++)
        weak[i] = weak[i - w] + n;
    sort(dist.begin(), dist.end());
    do {
        for (int i = 0; i < w; i++) {
            int start = weak[i]; //검사 시작 시점
            int finish = weak[i + w - 1]; //검사 종료 예상 시점
            for (int j = 0; j < dist.size(); j++) {
                start += dist[j];
                if (start >= finish) { //모든 지점 방문 완료시 탈출
                    answer = min(answer, j + 1);
                    break;
                }
                //다음 검사 시작 시점 구하기
                int next = upper_bound(weak.begin(), weak.end(), start) - weak.begin();
                start = weak[next];
            }
        }
    } while (next_permutation(dist.begin(), dist.end()));
    if (answer == 0x3f3f3f3f) answer = -1;
    return answer;
}