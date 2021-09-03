#include <string>
#include <sstream>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    stringstream ss(dartResult); // stringstream 초기화

    int scores[3] = { 0, };
    int options[3] = { 1, 1, 1 };

    for (int i = 0; i < 3; i++) {
        int score;
        char bonus;
        char option;

        ss >> score;
        bonus = ss.get();
        option = ss.get();

        if (option != '*' && option != '#') {
            ss.unget();
        }

        switch (bonus) {
        case 'S':
            scores[i] += pow(score, 1);
            break;
        case 'D':
            scores[i] += pow(score, 2);
            break;
        case 'T':
            scores[i] += pow(score, 3);
            break;
        default:
            break;
        }

        switch (option) {
        case '*':
            if (i > 0 && options[i - 1]) options[i - 1] *= 2;
            options[i] *= 2;
            break;
        case '#':
            options[i] *= -1;
            break;
        default:
            break;
        }
    }

    int answer = 0;
    for (int i = 0; i < 3; i++) {
        answer += scores[i] * options[i];
    }

    return answer;
}