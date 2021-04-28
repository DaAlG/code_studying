#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;

    vector<int> q;
    for (string s : operations) {
        if (s[0] == 'I') { // 큐에 숫자 삽입
            q.push_back(stoi(s.substr(2)));
            sort(q.begin(), q.end());
        }
        else if (s == "D 1" && !q.empty()) { // 최댓값 삭제
            q.pop_back();
        }
        else if (s == "D -1" && !q.empty()) { // 최솟값 삭제
            q.erase(q.begin());
        }
    }

    if (q.empty()) {
        answer.push_back(0);
        answer.push_back(0);
    }
    else {
        answer.push_back(q.back()); // 최댓값
        answer.push_back(q.front()); // 최솟값
    }

    return answer;
}