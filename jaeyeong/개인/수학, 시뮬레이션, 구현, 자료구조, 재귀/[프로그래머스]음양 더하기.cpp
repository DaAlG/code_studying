#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    int n = absolutes.size();
    int res;
    for (int i = 0; i < n; i++) {
        res = absolutes[i];
        res *= signs[i] == true ? 1 : -1;
        answer += res;
    }
    return answer;
}