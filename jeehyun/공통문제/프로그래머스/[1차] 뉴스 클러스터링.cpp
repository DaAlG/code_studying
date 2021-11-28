#include <string>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

bool isAlpha(char a) {
    return a >= 'a' && a <= 'z';
}

void makePair(map<string, int>& mp, string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    for (int i = 0; i < s.size() - 1; i++) {
        if (isAlpha(s[i]) && isAlpha(s[i + 1]))
            mp[s.substr(i, 2)]++;
    }
}

int solution(string str1, string str2) {

    map<string, int> s1;
    map<string, int> s2;
    makePair(s1, str1);
    makePair(s2, str2);

    map<string, int> mp;
    int total = 0;
    int inter = 0;
    for (auto [p, cnt] : s1) {
        mp[p]++;
        if (!s2[p]) {
            total += cnt;
        }
        else {
            total += max(cnt, s2[p]);
            inter += min(cnt, s2[p]);
        }
    }

    for (auto [p, cnt] : s2) {
        if (mp[p] == 0) {
            total += cnt;
        }
    }

    int answer = 0;
    if (total == 0)
        answer = 65536;
    else
        answer = (int)((float)inter / total * 65536);

    return answer;
}