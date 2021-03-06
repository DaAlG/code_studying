#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> dish;
map<int, int> maxsize;

void comb(vector<int> &course, string org, string s, int idx)
{
    if (idx == org.size()) {
        // 알파벳 오름차순으로 정렬
        sort(s.begin(), s.end());

        // 단품메뉴 개수가 course에 있다면 dish에 추가
        if (find(course.begin(), course.end(), s.size()) != course.end()) {
            dish[s]++;

            // 해당 단품메뉴들 주문횟수가 maxsize보다 크다면 maxsize 갱신
            if (maxsize[s.size()] < dish[s])
                maxsize[s.size()] = dish[s];
        }
        return;
    }

    // idx번째 단품메뉴 선택
    comb(course, org, s + org[idx], idx + 1);
    // idx번째 단품메뉴 선택 x
    comb(course, org, s, idx + 1);
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;

    // 각 손님들이 주문한 단품메뉴들로 코스요리 후보 생성
    for (int i = 0; i < orders.size(); i++) {
        comb(course, orders[i], "", 0);
    }

    // map을 vector로 변환
    vector<pair<string, int>> res(dish.begin(), dish.end());


    for (int i = 0; i < res.size(); i++) {
        int cnt = maxsize[res[i].first.size()];
       
        // 최소 2명 이상의 손님에게서 주문된 구성만 후보에 들어가므로 cnt > 1
        if (cnt > 1 && res[i].second == cnt)
            answer.push_back(res[i].first);
    }

    // 알파벳 오름차순으로 정렬
    sort(answer.begin(), answer.end());

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> orders = { "XYZ", "XWY", "WXA" };
    vector<int> course = { 2, 3, 4 };

    vector<string> result = solution(orders, course);
    for (string s : result) {
        cout << s << "\n";
    }
}