#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct mapNode {
    int num;
    string orgName, orgNum, tail;
    mapNode(int n, string _orgName, string _orgNum, string t) : num(n), orgName(_orgName), orgNum(_orgNum), tail(t) {};
};
map<string, vector<mapNode>> headSet;

bool isNumber(char x) {
    return '0' <= x && x <= '9';
}
bool isCapital(char x) {
    return 'A' <= x && x <= 'Z';
}

vector<string> parseString(string s) {
    vector<string> res;
    int idx = 0;
    string temp = "";
    while (!isNumber(s[idx])) {
        temp += s[idx++];
    }
    res.push_back(temp); temp = "";
    while (isNumber(s[idx])) {
        temp += s[idx++];
    }
    res.push_back(temp);
    res.push_back(s.substr(idx, s.size()-idx));
    return res;
}

string makeSmall(string s) {
    int idx = 0;
    string res = "";
    while (idx < s.size()) {
        if(isCapital(s[idx])) res += (s[idx++] - 'A' + 'a');
        else res += s[idx++];
    }
    return res;
}

bool compare(mapNode a, mapNode b) {
    return a.num < b.num;
}
vector<string> solution(vector<string> files) {
    vector<string> answer;
    vector<string> parseRes;

    for (int i = 0; i < files.size(); i++) {
        parseRes = parseString(files[i]);
        string head = makeSmall(parseRes[0]), number = parseRes[1], tail = parseRes[2];
        if (headSet.find(head) == headSet.end()) {
            vector<mapNode> v;
            headSet[head] = v;
        }
        headSet[head].push_back(mapNode(stoi(number), parseRes[0], number, tail));
    }

    for (map<string, vector<mapNode>>::iterator it = headSet.begin(); it != headSet.end(); it++) {
        string key = it->first;
        vector<mapNode> cur = it->second;
        stable_sort(cur.begin(), cur.end(), compare);
        for (int i = 0; i < cur.size(); i++) {
            answer.push_back(cur[i].orgName + cur[i].orgNum + cur[i].tail);
        }
    }
    return answer;
}

int main() {
    vector<string> files = { "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" };
    vector<string> answer = solution(files);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
}