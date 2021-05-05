#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for (int i = 0; i < prices.size() - 1; i++) {
        int idx = -1;
        int k = prices[i];

        for (int j = i + 1; j < prices.size(); j++) {
            if (k > prices[j]) {
                idx = j;
                break;
            }
        }

        if (idx == -1) answer[i] = prices.size() - i - 1;
        else answer[i] = idx - i;
    }

    return answer;
}