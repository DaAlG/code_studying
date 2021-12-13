using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

bool check(int a, int b) {
    return a > b;
}
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), check);
    int n = people.size();
    int sum = 0;
    int l = 0, r = n - 1;
    while (l < r) {
        sum = people[l] + people[r];
        if (sum > limit) {
            l++;
        }
        else {
            l++;
            r--;
        }
        answer++;
    }
    if (l == r) answer++;
    return answer;
}

int main() {
    vector<int> people = { 70, 50, 80, 50 };
    int limit = 100;
    cout << solution(people, limit);
}
