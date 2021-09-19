#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Trie {
private:
    int count; // 첫 문자부터 해당 노드의 문자까지를 접두사로 가지는 문자들의 개수
    Trie* nextNode[26]; // 26가지 알파벳에 대한 트라이
public:
    Trie() : count(0), nextNode() {}

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (nextNode[i]) delete nextNode[i];
        }
    }

    // 트라이에 문자열 삽입
    void insert(string str) {
        Trie* now = this;
        for (char ch : str) {
            now->count++;
            if (now->nextNode[ch - 'a'] == NULL)
                now->nextNode[ch - 'a'] = new Trie();
            now = now->nextNode[ch - 'a'];
        }
    }

    // 트라이에서 문자열 찾기
    int find(string str) {
        Trie* now = this;
        for (char ch : str) {
            if (ch == '?') // 검사하려는 접두사가 끝났다는 의미이므로 
                return now->count; // 현재 방문 중인 노드의 count를 리턴
            now = now->nextNode[ch - 'a'];
            if (now == NULL) // 트라이의 끝까지 도달할 때까지 일치하는 것이 없으면 해당 접두사로 일치하는 단어는 없다
                return 0;
        }
        return -1;
    }
};

Trie trieRoot[10000]; // 접두사 찾는 길이별 트라이
Trie reTrieRoot[10000]; // 접미사 찾는 길이별 트라이

vector<int> solution(vector<string> words, vector<string> queries) {
    for (string word : words) {
        trieRoot[word.size() - 1].insert(word); 
        reverse(word.begin(), word.end());
        reTrieRoot[word.size() - 1].insert(word);
    }

    vector<int> answer;
    for (string query : queries) {
        if (query[0] != '?') { // 접두사 탐색
            answer.push_back(trieRoot[query.size() - 1].find(query));
        }
        else { // 접미사 탐색
            reverse(query.begin(), query.end());
            answer.push_back(reTrieRoot[query.size() - 1].find(query));
        }
    }

    return answer;
}