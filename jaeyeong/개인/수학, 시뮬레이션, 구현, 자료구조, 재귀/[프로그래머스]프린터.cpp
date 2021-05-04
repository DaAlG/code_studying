using namespace std;
#include <iostream>
#include <string>
#include <vector>

bool check(vector<int> priorities) {
    int n = priorities.size();
    for (int i = 0; i < n; i++)
        if (priorities[i] < 0) return false;
    return true;
}
int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    bool pass = false, done=false;
    priorities[location] *= -1;
    while (!check(priorities)) {
        int c = priorities[0];
        priorities.erase(priorities.begin());
        for (int i = 0; i < (n-1); i++) {
            if( (c*priorities[i]>0 && c < priorities[i]) ||
                ( priorities[i] < 0 && c < -1*priorities[i]) ||
                (c < 0 && c * -1 < priorities[i]) ){
                priorities.push_back(c);
                pass = true;
                break;
            }
        }
        if (pass == true) {
            pass = false;
            continue;
        }
        answer++;
        n--;
    }
    return answer;
}

int main() {
    vector<int> priorities = { 1, 1, 9, 1, 1, 1 };
    int location = 0;
    cout << solution(priorities, location) << '\n';
}  