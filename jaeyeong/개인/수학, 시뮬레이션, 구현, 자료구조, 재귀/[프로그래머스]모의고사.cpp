#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> person[3];

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] = { 0,0,0 };
    int idx[3] = { 0,0,0 };
    person[0] = { 1, 2, 3, 4, 5 };
    person[1] = { 2, 1, 2, 3, 2, 4, 2, 5 };
    person[2] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 };


    for (int i = 0; i < answers.size(); i++) {
        for (int p = 0; p < 3; p++) {
            if (person[p][idx[p]] == answers[i]) score[p]++;
            idx[p]++;
            if (idx[p] == person[p].size()) idx[p] = 0;
        }
    }

    int maxScore = -1;
    for (int i = 0; i < 3; i++) {
        maxScore = max(maxScore, score[i]);
    }
    for (int i = 0; i < 3; i++)
        if (score[i] == maxScore) answer.push_back(i + 1);
    return answer;
}