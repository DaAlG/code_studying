#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    unordered_map<string, int> mp; // hash
    vector<string> keys;

    for (int i = 0; i < clothes.size(); i++) {
        if (!mp.count(clothes[i][1]))
            keys.push_back(clothes[i][1]);
        mp[clothes[i][1]]++;
    }

    for (int i = 0; i < keys.size(); i++) {
        // 의상 개수 + 안 입는 경우
        answer *= mp[keys[i]] + 1;
    }

    // 모두 입지 않는 경우 제외
    answer--;

    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<vector<string>> clothes = { {"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear" } };

    cout << solution(clothes);
    return 0;
}