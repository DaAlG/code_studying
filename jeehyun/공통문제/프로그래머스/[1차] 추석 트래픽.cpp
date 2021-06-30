#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 밀리초로 계산
int toMs(string s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    int ms = stoi(s.substr(9));
    return hh * 3600000 + mm * 60000 + ss * 1000 + ms;
}

// 시작시간 계산
int calc(int e, string t) {
    t.pop_back();
    int diff = 1000 * stof(t);

    int startMs = e - diff + 1;

    return startMs;
}

// 최대 처리량 계산
int getCnt(vector<pair<int, int>>& time, int start, int end) {
    int cnt = 0;
    for (int i = 0; i < time.size(); i++) {
        // 범위 안에 들어가지 않는다면 다음 로그 확인
        // start 포함 end 포함 X
        if (time[i].first >= end || time[i].second < start) continue;
        cnt++;
    }
    return cnt;
}

int solution(vector<string> lines) {
    vector<pair<int, int>> time;
    for (int i = 0; i < lines.size(); i++) {
        // 시작시간과 끝시간을 ms로 바꿔준다
        int end = toMs(lines[i].substr(11, 12));
        int start = calc(end, lines[i].substr(24));
        time.push_back({ start, end });
    }
    // 시작시간을 기준으로 오름차순
    sort(time.begin(), time.end());

    int answer = 0;
    for (int i = 0; i < time.size(); i++) {
        // 시작시간 ~ 시작시간 + 1000의 최대 처리량
        answer = max(answer, getCnt(time, time[i].first, time[i].first + 1000));
        // 끝시간 ~ 끝시간 + 1000의 최대 처리량
        answer = max(answer, getCnt(time, time[i].second, time[i].second + 1000));
    }

    return answer;
}