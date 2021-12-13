#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        answer += a[i] * b[i];
    }
    return answer;
}