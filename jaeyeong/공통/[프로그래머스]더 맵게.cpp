using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <queue>

bool check(int a, int K) {
    if (a <= K) return false;
    return true;
}
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> q;
    for (int i = 0; i < scoville.size(); i++) {
        q.push(-scoville[i]);
    }

    int first = -q.top();
    q.pop();
    int second = -q.top();
    q.pop();
    if (second != 0) {
        while (!check(first, K)) {
            int temp = first + second * 2;
            q.push(-temp);
            answer++;
            if (!q.empty()) {
                first = -q.top();
                q.pop();
            }
            else break;
            if (!q.empty()) {
                second = -q.top();
                q.pop();
            }
            else {
                if (first < K)
                    answer = -1;
                break;
            }
        }
    }
    else answer = -1;

    return answer;
}

int main() {
    vector<int> scoville = { 1,2,3,9,10,12 };
    int K = 7;
    cout << solution(scoville, K) << '\n';
}