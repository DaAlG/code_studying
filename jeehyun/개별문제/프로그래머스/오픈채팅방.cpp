#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> mp; // [유저 아이디] 사용자의 닉네임
    vector<pair<string, int>> log;
    for (string s : record) {
        stringstream ss(s);

        string cmd, id, nickname;
        ss >> cmd;
        ss >> id;

        if (cmd == "Enter") {
            ss >> nickname;
            mp[id] = nickname;
            log.push_back({ id, 1 });
        }
        else if (cmd == "Leave") {
            log.push_back({ id, 0 });
        }
        else if (cmd == "Change") {
            ss >> nickname;
            mp[id] = nickname;
        }
    }

    for (int i = 0; i < log.size(); i++) {
        if (log[i].second)
            answer.push_back(mp[log[i].first] + "님이 들어왔습니다.");
        else
            answer.push_back(mp[log[i].first] + "님이 나갔습니다.");
    }

    return answer;
}