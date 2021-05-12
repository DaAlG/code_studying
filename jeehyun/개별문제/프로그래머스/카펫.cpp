#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int total = brown + yellow;
    for (int i = 3; i <= sqrt(total); i++) {
        if (total % i == 0) {
            int col = total / i;
            int row = i;

            if (yellow == (col - 2) * (row - 2)) {
                answer.push_back(col);
                answer.push_back(row);
                break;
            }
        }
    }

    return answer;
}