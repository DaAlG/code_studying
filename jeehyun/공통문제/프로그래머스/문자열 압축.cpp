#include <string>
#include <vector>

using namespace std;

// 문자열 압축
string compress(string s, int k) {
    string res;
    string tmp = s.substr(0, k);
    int cnt = 1;

    for (int i = k; i < s.size(); i += k) {
        if (s.substr(i, k) == tmp) { // 같으면 반복 횟수 증가
            cnt++;
        }
        else { // 같지 않으면 압축 결과를 붙이고 다시 반복 체크
            if (cnt > 1) res += to_string(cnt);
            res += tmp;
            tmp = s.substr(i, k);
            cnt = 1;
        }
    }

    // 마지막에 남은 문자열을 붙여준다
    if (cnt > 1) res += to_string(cnt);
    res += tmp;

    return res;
}

int solution(string s) {
    int answer = s.size();

    for (int i = 1; i <= s.size(); i++) {
        string res = compress(s, i);
        if (answer > res.size()) {
            answer = res.size();
        }
    }

    return answer;
}