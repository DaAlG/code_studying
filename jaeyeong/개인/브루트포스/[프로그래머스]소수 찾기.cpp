#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
bool visit[8];
vector<int> v;
int ans = 0;
int n;
set<int> st;

int getInt(vector<int> mv) {
    string s = "";
    int k = 0;
    if (mv.empty() == true) return -1;
    for (int i = 0; i < mv.size(); i++) {
        s += v[mv[i]-1] + '0';
    }
    return stoi(s);
}

bool isT(int t) {
    if (t <= 1) return false;
    for (int i = 2; i < t; i++)
        if (t % i == 0) return false;
    return true;
}

void dfs(int depth) {
    if (depth == n+1) {
        vector<int> mv;
        for (int i = 1; i <= n; i++)
            if (visit[i])
                mv.push_back(i);
        sort(mv.begin(), mv.end());
        do {
            int t = getInt(mv);
            if (t == -1) return;
            if (st.find(t) == st.end() && isT(t)) {
                st.insert(t);
                ans++;
            }
        }while(next_permutation(mv.begin(), mv.end()));

        return;
    }
    visit[depth] = true;
    dfs(depth + 1);
    visit[depth] = false;
    dfs(depth + 1);
}
int solution(string numbers) {
    n = numbers.size();
    for (int i = 0; i < numbers.size(); i++)
        v.push_back(numbers[i] - '0');
    dfs(1);
    int answer = ans;
    return answer;
}

int main() {
    string numbers = "17";
    cout << solution(numbers);
}