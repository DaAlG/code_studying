using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>

map<string, int> wordsMap;
set<string> neighbor[51]; //0~n words¿« indx, n+1ø£ begin¿« index
int visit[51];

bool is_neighbor(string a, string b) {
	int cnt = 0;
	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) cnt++;
		if (cnt > 1) return false;
	}
	return cnt==1;
}
int solution(string begin, string target, vector<string> words) {
	queue<string> q;
	int n = words.size();
	q.push(begin);

	for (int i = 0; i < words.size(); i++)
		wordsMap.insert(make_pair(words[i], i));
	wordsMap.insert(make_pair(begin, n));
	if (wordsMap.find(target) == wordsMap.end()) return 0;

	for (int i = 0; i < words.size(); i++) {
		if (is_neighbor(words[i], begin)) {
			neighbor[n].insert(words[i]);
		}
		for (int j = i + 1; j < words.size(); j++) {
			if (is_neighbor(words[i], words[j])) {
				neighbor[wordsMap[words[i]]].insert(words[j]);
				neighbor[wordsMap[words[j]]].insert(words[i]);
			}
		}
	}

	while (!q.empty()) {
		string c = q.front();
		int cidx = wordsMap[c];
		q.pop();
		if (c == target) break;
		for (set<string>::iterator it = neighbor[cidx].begin(); it != neighbor[cidx].end(); it++) {
			if (!visit[wordsMap[*it]] && *it!=begin) {
				visit[wordsMap[*it]] = visit[cidx]+1;
				q.push(*it);
			}
		}
	}
	return visit[wordsMap[target]];
}

int main() {
	vector<string> words = { "hot", "dot", "dog", "lot", "log" };
	cout << solution("hit", "cog", words) << '\n';
}