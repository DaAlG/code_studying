#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<vector<int>, int> pvi;

map<string, int> mp;
vector<int> table[4 * 3 * 3 * 3];

void init() {
    mp["-"] = 0;
    mp["cpp"] = 1;
    mp["java"] = 2;
    mp["python"] = 3;
    mp["backend"] = 1;
    mp["frontend"] = 2;
    mp["junior"] = 1;
    mp["senior"] = 2;
    mp["chicken"] = 1;
    mp["pizza"] = 2;
}

pvi getInfo(string info) {
    stringstream ss(info);
    string tmp;
    int score;

    vector<int> list(4);
    int mult = 3 * 3 * 3;
    for (int i = 0; i < 4; i++) {
        ss >> tmp;
        if (tmp == "and") {
            i--;
            continue;
        }
        list[i] = mp[tmp] * mult;
        mult /= 3;
    }
    ss >> score;

    return { list, score };
}

void makeTable(string info) {
    auto [list, score] = getInfo(info);
    for (int i = 0; i < (1 << 4); i++) {
        int idx = 0;
        for (int j = 0; j < 4; j++) {
            if (i & (1 << j))
                idx += list[j];
        }
        table[idx].push_back(score);
    }
}

int find(string query) {
    auto [list, score] = getInfo(query);

    int idx = 0;
    for (int num : list) {
        idx += num;
    }

    int dist = 0;
    auto result = lower_bound(table[idx].begin(), table[idx].end(), score);

    return distance(result, table[idx].end());
}

vector<int> solution(vector<string> info, vector<string> query) {
    init();

    for (string f : info) {
        makeTable(f);
    }

    for (auto& t : table) {
        sort(t.begin(), t.end());
    }

    vector<int> answer;
    for (string q : query) {
        answer.push_back(find(q));
    }
    return answer;
}