#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// HH:MM 형태를 분으로 변환
int toMin(string time) {
    int result = stoi(time.substr(0, 2)) * 60;
    result += stoi(time.substr(3, 2));
    return result;
}

// 분을 HH:MM 형태로 변환
string toHM(int time) {
    string result = "";
    if ((time / 60) < 10) result += "0";
    result += to_string(time / 60);
    result += ":";
    if ((time % 60) < 10) result += "0";
    result += to_string(time % 60);
    return result;
}

string solution(int n, int t, int m, vector<string> timetable) {

    vector<int> crew;
    for (string t : timetable)
        crew.push_back(toMin(t));
    sort(crew.begin(), crew.end());

    int shuttle = 540; // 셔틀이 오는 시각
    int cIdx = 0; // 크루 인덱스
    int tanswer = 0; // 콘이 셔틀 타고 사무실에 갈 수 있는 가장 늦은 시각

    for (int i = 1; i <= n; i++, shuttle += t) {
        int cnt = 0;
        for (int j = cIdx; j < crew.size(); j++) {
            if (crew[j] <= shuttle) { // 셔틀에 탈 수 있는 크루들 태우기
                cIdx++;
                cnt++;
                if (cnt == m) // 최대 M명이 탔으므로 종료
                    break;
            }
        }

        if (i == n) { // 가장 마지막 셔틀일 경우
            if (cnt == m) tanswer = crew[cIdx - 1] - 1; // 자리가 없으면 더 일찍 오기
            else tanswer = shuttle; // 자리 있으면 타고 가기
        }
    }

    string answer = toHM(tanswer);
    return answer;
}