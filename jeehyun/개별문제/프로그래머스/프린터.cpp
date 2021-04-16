#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    vector<int> res;

    for (int i = 0; i < priorities.size(); i++)
        q.push({ i, i });

    while (!q.empty()) {
        int index = q.front().first;
        int doc = q.front().second;
        q.pop();

        bool check = false;
        for (int i = index + 1; i < priorities.size(); i++) {
            if (priorities[index] < priorities[i]) {
                check = true;
                break;
            }
        }

        if (check) { // 우선순위가 높은 문서가 있음 
            q.push({ priorities.size(), doc });
            priorities.push_back(priorities[index]);
        }
        else // 없으면 출력
            res.push_back(doc);
        priorities[index] = -1;
    }

    int answer;
    for (int i = 0; i < res.size(); i++) {
        if (res[i] == location) {
            answer = i + 1;
            break;
        }
    }

    return answer;
}

int main()
{
    vector<int> priorities = { 2, 1, 3, 2 };
    int location = 2;
    cout << solution(priorities, location);
    return 0;
}