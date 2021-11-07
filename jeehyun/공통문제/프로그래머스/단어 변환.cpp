#include <string>
#include <vector>
#include <queue>
#include <set>

using namespace std;

typedef pair<string, int> psi;
typedef pair<string, string> pss;

int getDiff(string a, string b) {
    int diff = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i])
            diff++;
    }
    return diff;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    set<string> word(words.begin(), words.end());
    set<string> visited;

    if (word.count(target)) {
        queue<psi> q;
        q.push({ begin, 0 });
        visited.insert(begin);

        while (!q.empty()) {
            auto [now, cnt] = q.front();
            q.pop();

            if (now == target) {
                answer = cnt;
                break;
            }

            for (auto next : word) {
                if (getDiff(now, next) == 1 && !visited.count(next)) {
                    visited.insert(next);
                    q.push({ next, cnt + 1 });
                }
            }
        }
    }

    return answer;
}