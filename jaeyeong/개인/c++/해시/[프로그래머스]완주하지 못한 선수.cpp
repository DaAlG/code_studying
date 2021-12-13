using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <set>


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    multiset<string> s;
    multiset<string>::iterator iter;

    for (int i = 0; i < participant.size(); i++) {
        s.insert(participant[i]);
    }
    for (int i = 0; i < completion.size(); i++) {
        iter = s.find(completion[i]);
        if (iter != s.end()) {
            s.erase(iter);
        }
    }
    answer += *s.begin();
    return answer;
}
int main() {
    vector<string> participant = { "leo", "kiki", "eden" };
    vector<string> completion = { "eden", "kiki" };
    cout << solution(participant, completion);
}