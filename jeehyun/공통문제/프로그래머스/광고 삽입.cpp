#include <string>
#include <vector>
#define MAX 360000

using namespace std;

long rTime[MAX];

long toSec(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    int s = stoi(time.substr(6, 2));
    return h * 3600 + m * 60 + s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int playTime = toSec(play_time);
    int advTime = toSec(adv_time);

    for (int i = 0; i < logs.size(); i++) {
        int start = toSec(logs[i].substr(0, 8));
        int end = toSec(logs[i].substr(9, 8));

        for (int j = start; j < end; j++)
            rTime[j]++;
    }


    for (int i = 1; i < playTime; i++)
        rTime[i] += rTime[i - 1];

    long max = rTime[advTime];
    int idx = 0;
    for (int i = 0; i < playTime - advTime; i++) {
        long sum = rTime[i + advTime] - rTime[i];
        if (sum > max) {
            max = sum;
            idx = i + 1;
        }
    }

    string answer = "";
    int s = idx % 60; idx = idx / 60;
    int m = idx % 60; idx = idx / 60;
    int h = idx;

    if (h < 10) answer += "0";
    answer += to_string(h);
    answer += ":";

    if (m < 10) answer += "0";
    answer += to_string(m);
    answer += ":";

    if (s < 10) answer += "0";
    answer += to_string(s);

    return answer;
}