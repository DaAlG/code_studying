#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;

    sort(people.begin(), people.end(), greater<int>());

    int first = 0;
    int second = people.size() - 1;

    while (first <= second) {
        if (first == second) { // 한 사람만 남은 경우
            answer++;
            break;
        }
        else if (people[first] + people[second] <= limit) { // 두 사람이 같이 탈 수 있는 경우
            answer++;
            first++;
            second--;
        }
        else { // 한 사람만 탈 수 있는 경우
            answer++;
            first++;
        }
    }

    return answer;
}

int main()
{
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;
    cout << solution(people, limit);
    return 0;
}