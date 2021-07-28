#include<iostream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
    int T = 10;

    for (int test_case = 1; test_case <= T; ++test_case) {
        cin >> test_case;

        string str, word;
        cin >> str >> word;

        int answer = 0;
        int pos = 0;
        while (word.find(str, pos) != string::npos) {
            answer++;
            pos = word.find(str, pos) + str.size();
        }
        cout << "#" << test_case << " " << answer << "\n";
    }

    return 0;
}