#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int maxDay = 0;
    for (int i = 0; i < progresses.size(); i++) {
        int day = ceil((double)(100 - progresses[i]) / speeds[i]);

        if (answer.empty() || maxDay < day) {
            answer.push_back(1);
            maxDay = day;
        }
        else {
            answer.back()++;
        }
    }

    return answer;
}