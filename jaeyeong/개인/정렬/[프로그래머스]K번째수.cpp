#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> v;
    for (int i = 0; i < commands.size(); i++) {
        int from = commands[i][0] - 1; //1
        int to = commands[i][1] - 1;//4
        int k = commands[i][2] - 1;//2
        for (int j = from; j <= to; j++)
            v.push_back(array[j]);
        sort(v.begin(), v.end());
        answer.push_back(v[k]);
        v.clear();
    }
    return answer;
}