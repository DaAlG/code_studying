#include <string>
#include <vector>
#include <stack>
#include <map>

using namespace std;

map<char, char> mp;

bool check(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == ')' || ch == ']' || ch == '}') {
            if (!st.empty() && st.top() == mp[ch])
                st.pop();
            else
                st.push(ch);
        }
        else
            st.push(ch);
    }

    if (st.empty())
        return true;
    return false;
}

int solution(string s) {
    int answer = 0;

    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';

    for (int i = 0; i < s.size(); i++) {
        if (check(s))
            answer++;

        // 회전
        s.insert(0, 1, s.back());
        s.pop_back();
    }

    return answer;
}