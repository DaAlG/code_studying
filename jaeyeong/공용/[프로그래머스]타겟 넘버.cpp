#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dfs(vector<int> numbers, int count, int sum, int target) {
    int answer = 0;
    if (count == numbers.size()) {
        if (sum == target)
            return 1;
        else
            return 0;
    }
    answer += dfs(numbers, count + 1, sum + numbers[count], target);
    answer += dfs(numbers, count + 1, sum - numbers[count], target);
    return answer;
}

int solution(vector<int> numbers, int target) {
    int answer = dfs(numbers, 0, 0, target);
    return answer;
}

int main() {
    vector<int> numbers = { 1,1,1,1,1 };
    int target = 3;

    int result =  solution(numbers, target);
    cout << result;
}
