#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int a, int b) {
    return a > b;
}
int solution(vector<int> citations) {
    int answer = 0;
    int n = citations.size();
    //6 5 3 1 0
    sort(citations.begin(), citations.end(), check);

    for (int i = citations[0]; i >= 0; i--) {
        int h = i;
        int cnt = 0;//cnt: h번 이상 인용된 논문 수
        for (int j = 0; j < n; j++) {
            if (citations[j] >= h)
                cnt++;
        }
        if (cnt >= h) {
            answer = h;
            break;
        }

    }
    return answer;
}

int main() {
    vector<int> citations = {3,0,6,1,5};
    cout << solution(citations);
}