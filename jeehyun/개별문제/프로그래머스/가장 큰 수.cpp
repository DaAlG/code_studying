#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool choose(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    // numbers의 숫자들을 string으로 변경
    vector<string> num_str;
    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < numbers.size(); i++) {
        num_str.push_back(to_string(numbers[i]));
    }

    // 가장 큰 수가 되도록 정렬
    sort(num_str.begin(), num_str.end(), choose);

    string answer = "";

    if (num_str[0] != "0") {
        for (string s : num_str) {
            answer += s;
        }
    }
    else {
        // 제일 앞 숫자가 0인 경우 모두 0
        answer = "0";
    }

    return answer;
}