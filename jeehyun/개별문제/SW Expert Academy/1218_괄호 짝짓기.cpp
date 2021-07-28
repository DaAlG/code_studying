#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> st;

bool isPair(char a, char b) {
    if (a == ')' && b == '(') return true;
    else if (a == ']' && b == '[') return true;
    else if (a == '}' && b == '{') return true;
    else if (a == '>' && b == '<') return true;
    return false;
}

int main(int argc, char** argv)
{
    int T = 10;
    for (int test_case = 1; test_case <= T; ++test_case) {
        int len;
        string br;
        cin >> len >> br;

        bool valid = true;
        for (char ch : br) {
            if (ch == '(' || ch == '[' || ch == '{' || ch == '<') {
                st.push(ch);
            }
            else {
                if (!isPair(ch, st.top())) {
                    valid = false;
                    break;
                }
                st.pop();
            }
        }

        cout << "#" << test_case << " ";
        if (valid) cout << 1 << "\n";
        else cout << 0 << "\n";

        while (!st.empty()) {
            st.pop();
        }
    }
    return 0;
}