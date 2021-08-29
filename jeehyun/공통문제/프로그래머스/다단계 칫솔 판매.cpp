#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> idx; // 조직 구성원의 인덱스 번호
map<string, string> parent; // 판매원의 추천인 정보

void go(vector<int>& answer, string now, int profit) {
    int d = profit * 0.1;
    answer[idx[now]] += profit - d; // 추천인에게 10%를 배분하고 나머지를 가짐

    // 추천인이 민호가 아니고 이익의 10%가 0보다 클 때까지 이익 분배
    if (parent[now] != "-" && d > 0) {
        go(answer, parent[now], d);
    }
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size());

    for (int i = 0; i < enroll.size(); i++) {
        idx[enroll[i]] = i;
        parent[enroll[i]] = referral[i];
    }

    for (int i = 0; i < seller.size(); i++) {
        go(answer, seller[i], amount[i] * 100); // 이익 분배
    }

    return answer;
}