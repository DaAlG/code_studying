#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// �и��ʷ� ���
int toMs(string s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    int ms = stoi(s.substr(9));
    return hh * 3600000 + mm * 60000 + ss * 1000 + ms;
}

// ���۽ð� ���
int calc(int e, string t) {
    t.pop_back();
    int diff = 1000 * stof(t);

    int startMs = e - diff + 1;

    return startMs;
}

// �ִ� ó���� ���
int getCnt(vector<pair<int, int>>& time, int start, int end) {
    int cnt = 0;
    for (int i = 0; i < time.size(); i++) {
        // ���� �ȿ� ���� �ʴ´ٸ� ���� �α� Ȯ��
        // start ���� end ���� X
        if (time[i].first >= end || time[i].second < start) continue;
        cnt++;
    }
    return cnt;
}

int solution(vector<string> lines) {
    vector<pair<int, int>> time;
    for (int i = 0; i < lines.size(); i++) {
        // ���۽ð��� ���ð��� ms�� �ٲ��ش�
        int end = toMs(lines[i].substr(11, 12));
        int start = calc(end, lines[i].substr(24));
        time.push_back({ start, end });
    }
    // ���۽ð��� �������� ��������
    sort(time.begin(), time.end());

    int answer = 0;
    for (int i = 0; i < time.size(); i++) {
        // ���۽ð� ~ ���۽ð� + 1000�� �ִ� ó����
        answer = max(answer, getCnt(time, time[i].first, time[i].first + 1000));
        // ���ð� ~ ���ð� + 1000�� �ִ� ó����
        answer = max(answer, getCnt(time, time[i].second, time[i].second + 1000));
    }

    return answer;
}