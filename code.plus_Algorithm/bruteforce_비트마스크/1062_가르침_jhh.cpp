/* 
 n개의 단어가 주어졌을 때
 k개의 글자로만 이루어진 단어의 개수를 고르는 문제 -> 각각의 단어에 대해서 모든 글자를 검사 
 -> 각각의 단어 n*15

 모든 단어는 anta로 시작하고
 모든 단어는 tica로 끝난다.
 n<=50, 단어의 길이 <=15

 경우의 수 21C(k-5) k-5개의 글자를 고르는 시간
 각단어를 구성하고 있는 알파벳이 무엇인지 알아야
 words[i] = i번째 단어를 구성하고 있는 알파벳을 비트마스크로 저장 하면 정수 비교만으로도 가능
 */
#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool learn[26];
int count(vector<string>& words) {
    int cnt = 0;
    for (string word : words) {
        bool ok = true;
        for (char x : word) {
            if (!learn[x - 'a']) {
                ok = false;
                break;
            }
        }
        if (ok) cnt += 1;
    }
    return cnt;
}
int go(int index, int k, vector<string>& words) {
    if (k < 0) return 0;
    if (index == 26) {
        return count(words);
    }
    int ans = 0;
    learn[index] = true;
    int t1 = go(index + 1, k - 1, words);
    learn[index] = false;
    if (ans < t1) ans = t1;
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        t1 = go(index + 1, k, words);
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<string> words(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
    }
    cout << go(0, m, words) << '\n';
    return 0;
}
