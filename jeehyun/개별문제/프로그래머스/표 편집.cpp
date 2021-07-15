#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(int n, int k, vector<string> cmd) {
    stack<int> st; // 삭제된 행
    vector<int> prev;
    vector<int> next;

    for (int i = 0; i < n + 2; i++) {
        prev.push_back(i - 1);
        next.push_back(i + 1);
    }
    k++;

    for (int i = 0; i < cmd.size(); i++) {
        if (cmd[i][0] == 'U') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                k = prev[k];
            }
        }
        else if (cmd[i][0] == 'D') {
            for (int j = 0; j < stoi(cmd[i].substr(2)); j++) {
                k = next[k];
            }
        }
        else if (cmd[i][0] == 'C') {
            st.push(k);
            next[prev[k]] = next[k];
            prev[next[k]] = prev[k];

            if (next[k] == n + 1) k = prev[k];
            else k = next[k];
        }
        else if (cmd[i][0] == 'Z') {
            int r = st.top();
            next[prev[r]] = r;
            prev[next[r]] = r;
            st.pop();
        }
    }

    string answer;
    answer.append(n, 'O');

    while (!st.empty()) {
        answer[st.top() - 1] = 'X';
        st.pop();
    }

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 8;
    int k = 2;
    vector<string> cmd = { "D 2","C","U 3","C","D 4","C","U 2","Z","Z" };
    cout << solution(n, k, cmd);
    return 0;
}