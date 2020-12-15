#include <iostream>
#include <vector>
#include <string>
using namespace std;
int count(int mask, vector<int>& words) {
    int cnt = 0;
    for (int word : words) {
        if ((word & ((1 << 26) - 1 - mask)) == 0) { //i번째 단어를 구성하는 알파벳
            //mask: 배운다고 한 알파벳
            //배우지 않은 알파벳이 단어의 있는지 검사해야 함(& 연산)
            cnt += 1;
        }
    }//모든 단어에 대해서 그 알파벳을 배운적 있는지 없는지 하나씩 다 뒤져야하지만 이거는 비트마스크로 해결 가능
   
    return cnt;
}
int go(int index, int k, int mask, vector<int>& words) {
    /*
    index: 알파벳
    k: 인덱스
    mask: 배운 알파벳의 비트마스크
    &words: 단어
    */
    if (k < 0) return 0; //배울 수 있는 단어 0개
    if (index == 26) {
        return count(mask, words); // 개수 세줌
    }
    int ans = 0;
    int t1 = go(index + 1, k - 1, mask | (1 << index), words);//index 번째 알파벳을 배우는 경우 배웠으니까 k-1, 비트마스크에 추가
    if (ans < t1) ans = t1;
    if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
        t1 = go(index + 1, k, mask, words);//배우지 않는 경우
        if (ans < t1) ans = t1;
    }
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> words(n);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (char x : s) {
            words[i] |= (1 << (x - 'a'));
        }
    }
    cout << go(0, m, 0, words) << '\n';
    return 0;
}
