#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(string s) {
    int answer = 0x3f3f3f3f;
    int n = s.size();
    string cur, res;
    vector<string> vec;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n; j+=i) {
            cur = s.substr(j, i);
            vec.push_back(cur);
        }
        for (int j = 0; j < vec.size(); j++) {
            int cnt = 1;
            cur = vec[j];
            while (j + 1 < vec.size() && cur == vec[j + 1]) {
                j++;
                cnt++;
            }
            if (cnt == 1)
                res += cur;
            else
                res += to_string(cnt) + cur;
        }
        answer = min((int)res.size(), answer);
        res.clear();
        cur.clear();
        vec.clear();
    }
    return answer;
}

int main() {
    string s = "aabbaccc";
    cout << solution(s);
}