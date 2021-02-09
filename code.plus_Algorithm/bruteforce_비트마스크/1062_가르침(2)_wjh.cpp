/*
 * 백준 1062 가르침
 * N개의 단어가 주어졌을 때 K개의 글자로만 이루어진 단어의 개수를 고르는 문제
 * 모든 단어는 anta로 시작하고 tica로 끝난다
 * N <= 50, 단어의 길이 <= 15
 * 먼저 a, n, t, i, c는 가르쳐야 한다
 * 즉, 26-5개의 글자 중에서 K-5개를 고르는 문제
 * 각 단어에 속해있는 알파벳이 무엇인지가 중요함
 * word[i] = i번째 단어에 포함되어 있는 알파벳의 비트마스크
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool learn[26];

int count(int mask, vector<int> &words)
{
	int cnt = 0;

	for (int word : words) {
		if ((word & ((1 << 26) - 1 - mask)) == 0) 
			cnt += 1;
	}
	return cnt;
}

int go(int index, int k, int mask, vector<int> &words)
{
	if (k < 0) return 0;

	if (index == 26) {
		return count(mask, words);
	}

	int ans = 0;
	int t1 = go(index + 1, k - 1, mask | (1 << index), words);

	if (ans < t1) ans = t1;
	if (index != 'a' - 'a' && index != 'n' - 'a' && index != 't' - 'a' && index != 'i' - 'a' && index != 'c' - 'a') {
		t1 = go(index + 1, k, mask, words);
		if (ans < t1) ans = t1;
	}
	return ans;
}

int main()
{
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
	cout << go(0, m, 0, words) << endl;
	return 0;
}