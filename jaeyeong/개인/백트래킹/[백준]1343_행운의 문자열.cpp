using namespace std;
#include <iostream>
#include <string>
#include <vector>

int alpha[27];
int n;
int arr[10];
int answer;

void solve(int cnt) {
    if (cnt == n) {
        answer++;
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) continue;
        if (cnt != 0 && arr[cnt - 1] == i) continue;
        alpha[i]--;
        arr[cnt] = i;
        solve(cnt + 1);
        alpha[i]++;
    }
}
int main() {
    string s;
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        alpha[s[i] - 'a']++;
    }
    solve(0);
    cout << answer << '\n';
}