//������, ��������, ��ü �ҿ�ð��� �ʴ����� �ٲٱ�
//īī���� ��� �ð� ���ڿ�
#include <string>
#include <vector>
#include <queue>

using namespace std;
int ad[360000];

//���ڿ� -> ��(int)��
int strToSec(string s) {
    int ret = 0;
    string h = s.substr(0, 2);
    string m = s.substr(3, 2);
    string c = s.substr(6, 2);
    ret += stoi(h)*60*60;
    ret += stoi(m)*60;
    ret += stoi(c);
    return ret;
}
//��(int) -> ���ڿ���
string secToStr(int n) {
    string ret = "";
    int s = n % 60; n /= 60;
    int m = n % 60; n /= 60;
    int h = n;
    if (h < 10) ret += "0";
    ret += to_string(h);
    ret += ":";

    if (m < 10) ret += "0";
    ret += to_string(m);
    ret += ":";

    if (s < 10) ret += "0";
    ret += to_string(s);

    return ret;
}
string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    for (string s : logs) {
        int start = strToSec(s.substr(0, 8));
        int finish = strToSec(s.substr(9, 8));
        for (int i = start; i < finish; i++)
            ad[i]++;
    }
    int n = strToSec(play_time); //��ü ���� ����
    int len = strToSec(adv_time); //���� ���� ����

    int idx = 0;
    long long sum = 0;
    long long maxSum = 0;

    queue<int> q;

    for (int i = 0; i < len; i++) {
        sum += ad[i];
        q.push(ad[i]);
    }
    maxSum = sum;

    //ť�� �̿��� ��������
    for (int i = len; i < n; i++) {
        sum += ad[i];
        q.push(ad[i]);
        sum -= q.front();
        q.pop();
        if (sum > maxSum) {
            idx = i - len + 1;
            maxSum = sum;
        }
    }
    answer = secToStr(idx);
    return answer;
}