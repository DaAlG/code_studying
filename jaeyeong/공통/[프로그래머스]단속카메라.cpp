using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    vector<int> camera;
    sort(routes.begin(), routes.end(), compare);
    camera.push_back(routes[0][1]);
    for (int i = 1; i < routes.size(); i++) {
        int start = routes[i][0];
        int end = routes[i][1];
        int lastCamera = camera.back();
        if (start <= lastCamera && lastCamera <= end) continue;
        camera.push_back(end);
    }
    return answer=camera.size();
}

int main() {
    vector<vector<int>> routes = { {-20, -15},{-14, -5},{-18, -13},{-5, -3} };
    cout << solution(routes) << '\n';
    return 0;
}