using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    set<string> gem(gems.begin(), gems.end()); //보석의 종류
    map<string, int>selected; //(보석, 보석 포함 개수)
    int start = 0, end = 0;
    int minDist = gems.size();
    int ansStart= 1 , ansEnd = gems.size();

    while (1) {
        if (minDist == 0) break;
        //모든 보석이 다 담긴 경우
        if (selected.size() == gem.size()) {
            if (minDist > end - start) {
                minDist = end - start;
                ansStart = start + 1;
                ansEnd = end;
            }
            //보석이 하나면 제거하고 시작 인덱스 증가
            if (selected[gems[start]] == 1) {
                selected.erase(gems[start]);
                start++;
            }
            //같은 종류의 보석이 여러 개면 1개 감소시키고 시작 인덱스 증가
            else if (selected[gems[start]] > 1) {
                selected[gems[start]]--;
                start++;
            }
        }
        //끝까지 탐색하면 종료
        else if (end == gems.size()) break;
        //보석 종류를 다 포함하지 못하면 end 인덱스 증가
        else {
            selected[gems[end]]++;
            end++;
        }
    }

    answer.push_back(ansStart);
    answer.push_back(ansEnd);
    return answer;
}

int main() {
    vector<string> gems = { "ZZZ", "YYY", "NNNN", "YYY", "BBB" };
    vector<int> ans = solution(gems);
}

/*
* 이 문제를 처음 읽고 떠올랐던 알고리즘은 LIS.
* LIS 비슷하게 코드를 짜봤지만 최악의경우 100000*100000에 가까운 시간복잡도라 역시 오답이다 ^_ㅠ
* 종만북엔 투포인터를 따로 소개하진 않는데.. 6월 중에 학습하는 날 꼭 만들어 둬야지.
* 효용성 빵점 코드
int length[MAX];
set<string> gem;
int minV = MAX + 1;
int ans = MAX + 1;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int n = gems.size();
    for (int i = 0; i < n; i++)
        gem.insert(gems[i]);

    for (int k = 0; k < n; k++) {
        set<string> selected;
        length[k] = MAX + 1;
        for (int i = k; 0 <= i; i--) {
            if (selected.find(gems[i]) == selected.end())
                selected.insert(gems[i]);
            if (gem == selected) {
                length[k] = i;
                if (k - i < minV) {
                    minV = k - i;
                    ans = k;
                }
                break;
            }
        }
    }
    answer.push_back(length[ans]+1);
    answer.push_back(ans+1);
    return answer;
}
*
*/