#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> routes) {
    sort(routes.begin(), routes.end());

    int answer = 1;
    int end = routes[0][1];

    for (auto route : routes) {
        if (end >= route[0]) {
            end = min(end, route[1]);
        }
        else {
            answer++;
            end = route[1];
        }
    }
    return answer;
}