#include <string>
#include <vector>
#include <algorithm>
#include <map>

#define psi pair<string, int>
#define pii pair<int, int>

using namespace std;

bool cmp(psi a, psi b) {
    return a.second > b.second;
}

bool cmp2(pii a, pii b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> tPlays; // 장르별 재생 횟수
    map<string, vector<pii>> mp; // 장르에 속한 곡의 인덱스

    for (int i = 0; i < genres.size(); i++) {
        tPlays[genres[i]] += plays[i];
        mp[genres[i]].push_back({ i, plays[i] });
    }

    // 장르별 재생 횟수를 map -> vector + 재생 횟수에 대해 내림차순 정렬
    vector<psi> seq(tPlays.begin(), tPlays.end());
    sort(seq.begin(), seq.end(), cmp);

    vector<int> answer;
    for (psi genre : seq) {
        // 각 노래의 재생 횟수에 대해 내림차순 정렬
        vector<pii> song = mp[genre.first];
        sort(song.begin(), song.end(), cmp2);

        // 두 개씩 모아서 베스트 앨범에 추가
        // 하나일 경우에는 한 곡만 선택
        for (int i = 0; i < 2 && i < song.size(); i++) {
            answer.push_back(song[i].first);
        }
    }

    return answer;
}