#include <string>
#include <vector>
#include <set>
#include <iostream>

using namespace std;

set<int> list;
bool check[8];

bool matches(string bId, string uId) {
    if (bId.size() != uId.size())
        return false;

    for (int i = 0; i < bId.size(); i++) {
        if (bId[i] == '*') continue;
        else if (bId[i] != uId[i]) return false;
    }
    return true;
}

void go(vector<string>& bId, vector<string>& uId, int now, int flag) {
    if (bId.size() == now) {
        list.insert(flag);
        return;
    }

    for (int i = 0; i < uId.size(); i++) {
        if (!check[i] && matches(bId[now], uId[i])) {
            check[i] = true;
            go(bId, uId, now + 1, flag | (1 << i));
            check[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    go(banned_id, user_id, 0, 0);
    return list.size();
}