#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toBinary(int n) {
    string b;
    while (n) {
        b += to_string(n % 2);
        n /= 2;
    }
    return b;
}

vector<int> solution(string s) {
    vector<int> answer;

    int cnt = 0;
    int zero = 0;

    while (s != "1") {
        int n = s.size();

        while (1) {
            auto res = find(s.begin(), s.end(), '0');

            if (res == s.end())
                break;

            s.erase(res);
            zero++;
        }

        s = toBinary(s.size());
        cnt++;
    }

    answer.push_back(cnt);
    answer.push_back(zero);

    return answer;
}

int main()
{
    string s = "110010101001";
    vector<int> answer = solution(s);
    cout << answer[0] << ' ' << answer[1];
    return 0;
}