#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#define MAX 501

using namespace std;

bool cmp(string a, string b) {
    if (a.size() == b.size())
        return a < b;
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<string> tuple; // 튜플을 표현하는 집합을 담는 벡터

        // 튜플 집합을 구한다
    for (int i = 2; i < s.size() - 1; i++) {
        int j;
        for (j = i; s[j] != '}'; j++);
        tuple.push_back(s.substr(i, j - i));
        i = j + 2;
    }

    // 집합 사이즈를 오름차순으로 정렬
    sort(tuple.begin(), tuple.end(), cmp);

    vector<int> answer;
    set<int> num;

    for (int i = 0; i < tuple.size(); i++) {
        string tmp;
        for (char ch : tuple[i]) {
            if (ch >= '0' && ch <= '9')
                tmp += ch;
            else {
                int n = stoi(tmp);
                if (!num.count(n)) {
                    num.insert(n);
                    answer.push_back(n);
                }
                tmp.clear();
            }
        }

        if (!num.count(stoi(tmp))) {
            num.insert(stoi(tmp));
            answer.push_back(stoi(tmp));
        }
    }

    return answer;
}