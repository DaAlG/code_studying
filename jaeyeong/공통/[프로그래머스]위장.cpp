using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

vector<int> v;
int ans = 0;
int visit[40], arr[40];


int solution(vector<vector<string>> clothes) {
    int answer = 1, n, m;
    
    set<string> st;
    map<string, int> mp;
    set<string>::iterator iter;
  
    for (int i = 0; i < clothes.size(); i++) {
        st.insert(clothes[i][1]);
    }
    for (iter = st.begin(); iter != st.end(); iter++) {
        mp.insert(make_pair(*iter, 0));
    }
    n = st.size();
    for (int i = 0; i < clothes.size(); i++) {
        mp[clothes[i][1]]++;
    }
    for (iter = st.begin(); iter != st.end(); iter++)
        v.push_back(mp[*iter]);

    for (int i = 0; i < n; i++) {
        answer *= (v[i] + 1);
    }

    return answer-1;
}

int main() {
    vector<vector<string>> clothes = { {"crowmask", "face"},{"bluesunglasses", "face"},{"smoky_makeup", "face"} };
    cout << solution(clothes) << '\n';
}