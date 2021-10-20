#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

map<ll, ll> room;

ll findNext(ll n) {
    if (room[n] == 0) return n;
    return room[n] = findNext(room[n]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<ll> answer;

    for (auto n : room_number) {
        if (room[n] == 0) { // 해당 방이 비어있는 경우
            answer.push_back(n);
            room[n] = findNext(n + 1);
        }
        else { // 비어있지 않으면 조건에 맞는 방을 찾는다
            ll next = findNext(n);
            answer.push_back(next);
            room[next] = findNext(next + 1);
        }
    }

    return answer;
}