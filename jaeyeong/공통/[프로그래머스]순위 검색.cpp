#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

//const int cpp = 0, java = 1, python = 2;
//const int backend = 0, frontend = 1;
//const int junior = 0, senior = 1;
//const int chicken = 0, pizza = 1;
map<string, int> constmp;
vector<int> applicants[3][2][2][2];
int n;

void setconst(int _n) {
    n = _n;
    constmp.insert(make_pair("cpp", 0));
    constmp.insert(make_pair("java", 1));
    constmp.insert(make_pair("python", 2));
    constmp.insert(make_pair("backend", 0));
    constmp.insert(make_pair("frontend", 1));
    constmp.insert(make_pair("junior", 0));
    constmp.insert(make_pair("senior", 1));
    constmp.insert(make_pair("chicken", 0));
    constmp.insert(make_pair("pizza", 1));
    constmp.insert(make_pair("-", -1));
}

vector<int> parse(string info, int maxnum, int cntnum) {
    vector<int> res;
    string temp;
    int cnt = 0;
    for (int i = 0; i < maxnum; i++) {
        if (info[i] == ' ') {
            int value = constmp[temp];
            res.push_back(value);
            temp = "";
            cnt++;
            if(cnt<4 && cntnum==4)
                i += cntnum;
        }
        else temp += info[i];
    }
    res.push_back(stoi(temp));
    return res;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    setconst(info.size());
    for (int i = 0; i < n; i++) {
        vector<int> res = parse(info[i], info[i].size(), 0);
        applicants[res[0]][res[1]][res[2]][res[3]].push_back(res[4]);
    }
    for (int lan = 0; lan < 3; lan++) {
        for (int pos = 0; pos < 2; pos++) {
            for (int age = 0; age < 2; age++) {
                for (int food = 0; food < 2; food++) {
                    sort(applicants[lan][pos][age][food].begin(), applicants[lan][pos][age][food].end());
                }
            }
        }
    }
    for (int i = 0; i < query.size(); i++) {
        vector<int> res = parse(query[i], query[i].size(), 4);
        int ans = 0;
        int lan = res[0], pos = res[1], age = res[2], food = res[3], score = res[4];
        int slan = lan == -1 ? 0 : lan;
        int elan = lan == -1 ? 3 : lan + 1;
        int spos = pos == -1 ? 0 : pos;
        int epos = pos == -1 ? 2 : pos + 1;
        int sage = age == -1 ? 0 : age;
        int eage = age == -1 ? 2 : age + 1;
        int sfood = food == -1 ? 0 : food;
        int efood = food == -1 ? 2 : food + 1;
        for (lan = slan; lan < elan; lan++) {
            for (pos = spos; pos < epos; pos++) {
                for (age = sage; age < eage; age++) {
                    for (food = sfood; food < efood; food++) {
                        int size = applicants[lan][pos][age][food].size();
                        if (size == 0) continue;
                        
                        auto iter = lower_bound(applicants[lan][pos][age][food].begin(), applicants[lan][pos][age][food].end(), score);
                        if (iter == applicants[lan][pos][age][food].end()) continue;
                        ans += size - (iter - applicants[lan][pos][age][food].begin());
                    }
                }
            }
        }
        answer.push_back(ans);
    }
    return answer;
}

int main() {
    vector<string> info = { "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50" };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    vector<int> answer = solution(info, query);
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << ' ';
}