#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    vector<int> ternary;
    while (n) {
        ternary.push_back(n % 3);
        n /= 3;
    }

    int answer = 0;
    int mult = 1;
    for (int i = ternary.size() - 1; i >= 0; i--) {
        answer += ternary[i] * mult;
        mult *= 3;
    }

    return answer;
}

int main()
{
    int n = 45;
    cout << solution(n);
    return 0;
}