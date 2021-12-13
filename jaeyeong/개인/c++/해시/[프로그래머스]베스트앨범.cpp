#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>

using namespace std;
map<string, int> genre;
//�������ȣ>�帣, �帣>>�帣������ȣ

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    vector<pair<int,int>> playlist[100]; //�帣�� i�� ������ȣ k�� ���� pair(k,Ƚ��)�� playlist[i]�� �ֱ�
    pair<int,int> playtime[100]; //�帣 i�� total �÷���Ÿ���� pair(i,��Ż �÷���Ÿ��)���� ����
    int n = genres.size(), m=0; //m�� �帣������ ����

    for (int i = 0; i < n; i++) {
        //genre���� �帣 ������ȣ(0����)
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