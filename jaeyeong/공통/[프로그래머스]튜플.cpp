#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int number[100001];


void check(string s) {
    size_t it;
    while ((it = s.find(",")) != string::npos) {
        string input = s.substr(0, it);
        s = s.substr(it + 1);
        number[stoi(input)]++;
    }
    number[stoi(s)]++;
    return;
}

vector<int> solution(string s) {
    vector<int> answer;
    string nextS = s.substr(1), thisS="", longest;
    size_t it, next;

    while ((it = nextS.find("{")) != string::npos) {
        next = nextS.find("}");
        thisS = nextS.substr(it + 1, next - it - 1);
        check(thisS);
        if (thisS.size() > longest.size())
            longest = thisS;
        nextS = nextS.substr(next+1);
    }

    vector<pair<int, int>> v;
    while ((it = longest.find(",")) != string::npos) {
        string input = longest.substr(0, it);
        longest = longest.substr(it + 1);
        v.push_back(make_pair(-1*number[stoi(input)], stoi(input)));
    }
    v.push_back(make_pair(-1*number[stoi(longest)], stoi(longest)));

    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
        answer.push_back(v[i].second);
    return answer;
}

int main() {
    string s = "{{20,111},{111}}";
    vector<int> v = solution(s);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
}