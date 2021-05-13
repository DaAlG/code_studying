#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

string u = "", v = "";
int n;

void seperate(string p) {
    stack<char> st;
    n = p.size();
    char start = p[0];
    st.push(start);
    for (int i = 1; i < n; i++) {
        if (p[i] == start)
            st.push(p[i]);
        else {
            st.pop();
            if (st.empty()) {
                u = p.substr(0, i + 1);
                v = p.substr(i+1, n - i - 1);
                return;
            }
        }
    }
    u += p;
    return;
}

bool isrightString(string p) {
    //올바른 문자열인지 확인
    stack<char> st;
    n = p.size();
    if (p[0] == ')') return false;
    for (int i = 0; i < n; i++) {
        if (p[i] == '(') {
            st.push(p[i]);
        }
        else {
            if (st.empty()) {
                return false;
            }
            else {
                st.pop();
            }
        }
    }
    return true;
}
string solution(string p) {
    string answer = "";
    string cu, cv;
    //1단계
    if (p == "") return answer;
    //2단계
    seperate(p);
    cu = u;
    cv = v;
    u.clear();
    v.clear();
    //3단계
    if (isrightString(cu)) {
        answer += cu;
        answer += solution(cv);
    }
    else { //4단계
        answer += '(';
        answer += solution(cv);
        answer += ')';
        cu.erase(0, 1);
        cu.erase(cu.size() - 1, 1);
        for (int i = 0; i < cu.size(); i++) {
            if (cu[i] == '(') cu[i] = ')';
            else cu[i] = '(';
        }
        answer += cu;
    }
    return answer;
}

int main() {
    string p = ")()()()(";
    cout<<solution(p);
}