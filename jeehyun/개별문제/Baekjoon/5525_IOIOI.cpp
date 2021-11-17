/*
 * BOJ 5525 IOIOI
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> fail(string pattern)
{
    int m = pattern.length();
    vector<int> pi(m);

    pi[0] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            pi[i] = ++j;
    }
    return pi;
}

int kmp(string pattern, string text)
{
    int m = pattern.length();
    int n = text.length();

    vector<int> pi = fail(pattern);
    int pos = 0;

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];
        if (text[i] == pattern[j]) {
            if (j == m - 1) {
                pos++;
                j = pi[j];
            }
            else j++;
        }
    }
    return pos;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    string s;
    cin >> n >> m >> s;

    string p = "I";
    for (int i = 0; i < n; i++)
        p +="OI";

    cout << kmp(p, s);
    return 0;
}
