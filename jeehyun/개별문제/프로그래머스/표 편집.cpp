#include <string>
#include <vector>
#include <list>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    vector<bool> deleted(n); // true : 삭제된 행
    vector<int> st;
    list<int> table;

    for (int i = 0; i < n; i++) table.push_back(i);

    auto cur = table.begin();
    for (int i = 0; i < k; i++) cur++;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                cur--;
            }
        }
        else if (cmd[i][0] == 'D') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                cur++;
            }
        }
        else if (cmd[i][0] == 'C') {
            deleted[*cur] = true;
            st.push_back(*cur);

            auto now = cur;

            if (*cur == table.back()) cur--;
            else cur++;
            table.erase(now);
        }
        else if (cmd[i][0] == 'Z') {
            deleted[st.back()] = false;
            table.push_back(st.back());
            table.sort();
            st.pop_back();
        }
    }

    string answer = "";
    for (int i = 0; i < deleted.size(); i++) {
        if (deleted[i]) answer += 'X';
        else answer += 'O';
    }
    return answer;
}