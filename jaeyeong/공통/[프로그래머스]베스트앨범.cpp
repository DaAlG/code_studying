#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> gInfo; // (장르, 장르번호)


bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) return a.second > b.second;
    else a.first < b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int n = genres.size();
    int m = 0;
    //0. (장르, 장르번호) set
    for (int i = 0; i < n; i++) {
        if (gInfo.find(genres[i]) == gInfo.end())
            gInfo.insert(make_pair(genres[i], m++));
    }
    //1. 장르 재생순 정렬
    vector<pair<int, int>> gPlaytime; //(장르번호, 장르플레이횟수)
    for (int i = 0; i < m; i++)
        gPlaytime.push_back(make_pair(i, 0));
    for (int i = 0; i < n; i++)
        gPlaytime[gInfo[genres[i]]].second += plays[i];
    sort(gPlaytime.begin(), gPlaytime.end(), compare);

    //2. 곡 재생순 장르별 정렬
    vector<pair<int, int>> musicInfo[100];
    // musicInfo[i] 엔 장르가 i인 곡이 (곡 고유번호, 플레이횟수) 꼴로 들어가 있다.
    for (int i = 0; i < n; i++)
        musicInfo[gInfo[genres[i]]].push_back(make_pair(i, plays[i]));
    for (int i = 0; i < n; i++)
        sort(musicInfo[i].begin(), musicInfo[i].end(), compare);

    //3. answer조합
    for (int i = 0; i < m; i++) {
        int curGenre = gPlaytime[i].first;
        for (int j = 0; j < 2; j++) {
            if (j == 1 && musicInfo[curGenre].size() == 1) continue;
            answer.push_back(musicInfo[curGenre][j].first);
        }
    }
    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    solution(genres, plays);
}