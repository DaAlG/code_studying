#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> getInfo(string s) {
    vector<string> res;

    for (int i = 0; i < s.size(); i++) {
        int j = i;
        while (j < s.size() && s[j] != ' ') j++;
        res.push_back(s.substr(i, j - i));
        i = j;
    }

    return res;
}

vector<string> solution(vector<string> record) {
    vector<pair<string, bool>> log;
    map<string, string> nickname;

    for (string rec : record) {
        vector<string> info = getInfo(rec);

        if (info[0] == "Enter") {
            nickname[info[1]] = info[2];
            log.push_back({ info[1], true });
        }
        else if (info[0] == "Leave") {
            log.push_back({ info[1], false });
        }
        else if (info[0] == "Change") {
            nickname[info[1]] = info[2];
        }
    }

    vector<string> answer;
    for (int i = 0; i < log.size(); i++) {
        if (log[i].second)
            answer.push_back(nickname[log[i].first] + "님이 들어왔습니다.");
        else
            answer.push_back(nickname[log[i].first] + "님이 나갔습니다.");
    }

    return answer;
}