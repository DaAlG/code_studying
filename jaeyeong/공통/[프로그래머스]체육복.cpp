using namespace std;

#include <iostream>
#include <string>                                
#include <vector>
#include <stack>


int solution(int n, vector<int> lost, vector<int> reserve) {
    stack<int> s;
    int students[31] = {};
    int answer = 0, count = 0;

    for (int i = 0; i < reserve.size(); i++)
        students[reserve[i]] = 1;

    for (int i = 0; i < lost.size(); i++) {
        if (students[lost[i]] == 1) {
            students[lost[i]] = 0;
            continue;
        }
        students[lost[i]] = -1;
        count++;
    }
        
    answer = n - count;


    for (int i = 1; i <= n; i++) {
        if (students[i] == -1)
            s.push(i);
        else if (students[i] == 1) {
            if (s.empty()!=true && i - s.top() == 1) {
                answer++;
                s.pop();
            }
            else if (i < n && students[i + 1]==-1) {
                answer++;
                i++;
            }
        }
    }
    while (!s.empty()) {
        s.pop();
    }
    return answer;
}

int main() {
    int n = 5;
    vector<int> lost = { 2, 4 }, reserve = { 3 };
    cout << solution(n, lost, reserve) << '\n';
}