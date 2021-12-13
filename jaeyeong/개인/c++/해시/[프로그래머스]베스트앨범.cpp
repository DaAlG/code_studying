#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;
map<string, int> genre;
//곡고유번호>장르, 장르>>장르고유번호

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int,int>> playlist[100]; //장르가 i인 고유번호 k인 곡을 pair(k,횟수)로 playlist[i]에 넣기
    pair<int,int> playtime[100]; //장르 i의 total 플레이타임을 pair(i,토탈 플레이타임)으로 저장
    int n = genres.size(), m=0; //m은 장르종류의 개수

    for (int i = 0; i < n; i++) {
        //genre에는 장르 고유번호(0부터)
        if (genre.find(genres[i]) == genre.end())
            genre.insert(make_pair(genres[i], m++));
    }

    for (int i = 0; i < m; i++)
        playtime[i] = make_pair(i, 0);

    for (int i = 0; i < n; i++) {
        playlist[genre[genres[i]]].push_back(make_pair(i, plays[i]));
        playtime[genre[genres[i]]].second += plays[i];
    }
    
    sort(playtime, playtime + m, compare);
    for (int i = 0; i < n; i++)
        sort(playlist[i].begin(), playlist[i].end(), compare);

    for (int i = 0; i < m; i++) {
        int cur_genre = playtime[i].first;
        for (int j = 0; j < 2; j++) {
            if (j == 1 && playlist[cur_genre].size() == 1) continue;
            answer.push_back(playlist[cur_genre][j].first);
        }
    }
    

    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };
    solution(genres, plays);
}