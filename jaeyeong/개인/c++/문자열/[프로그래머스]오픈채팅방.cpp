#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;
map<string, string> uid;

vector<string> split(string input, char delimiter) {
    vector<string> res;
    stringstream ss(input);
    string temp;
    while (getline(ss, temp, delimiter)) {
        res.push_back(temp);
    }
    return res;
}

vector<string> solution(vector<string> record) {
    vector<pair<string,string>> message;
    vector<string>answer;
    for (int i = 0; i < record.size(); i++) {
        vector<string> parsed  = split(record[i], ' ');
        string order = parsed[0], id = parsed[1];
        if (order != "Leave") {
            string nickname = parsed[2];
            if (uid.find(id) == uid.end()) uid.insert(make_pair(id, nickname));
            else uid[id] = nickname;
        }
        if(order != "Change")
        message.push_back(make_pair(order, id));
    }
    for (int i = 0; i < message.size(); i++) {
        string order = message[i].first;
        string id = message[i].second;
        string toput = uid[id] + "님이 ";
        if (order == "Enter") toput += "들어왔습니다.";
        else toput += "나갔습니다.";
        answer.push_back(toput);
    }
    return answer;
}

int main() {
    vector<string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan","Leave uid1234" };
    vector<string> answer = solution(record);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << '\n';
}