#include <string>
#include <vector>
#include <iostream>

using namespace std;


int toTimes(string s) {
    int idx = s.find(':');
    int hour = stoi(s.substr(0, idx)) *60 *60 *1000;
    s = s.substr(idx+1);
    idx = s.find(':');
    int minutes = stoi(s.substr(0, idx)) *60 *1000;
    s = s.substr(idx+1);
    s.erase(s.begin() + 2, s.begin() + 3);
    int sec = stoi(s);
    return hour+minutes+sec;
}

int getProcessTime(string taken) {
    int idx = taken.find('s');
    taken = taken.substr(0, idx);
    double d = stod(taken);
    int tsec = d * 1000;

    return tsec;
}
int solution(vector<string> lines) {
    int answer = -1;
    int n = lines.size();
    vector<int> process;
    vector<int> end_point;
    for (int i = 0; i < n; i++) {
        string finish = lines[i].substr(11);
        int t = finish.find(' ');
        string taken = finish.substr(t + 1);
        finish = finish.substr(0, t);
        process.push_back(getProcessTime(taken));
        end_point.push_back(toTimes(finish));
    }

    int next_startTime, furTime;
    for (int i = 0; i < n; i++) {
        int tmp = 0;
        furTime = end_point[i] + 1000;
        for (int j = i + 1; j < n; j++) {
            next_startTime = end_point[j] - process[j] + 1;
            if (next_startTime < furTime)
                tmp++;
        }
        answer = max(answer, tmp);
    }
    return answer + 1;
}

int main() {
    vector<string> lines = { "2016-09-15 23:59:59.999 0.001s" };
    cout<<solution(lines)<<'\n';
}