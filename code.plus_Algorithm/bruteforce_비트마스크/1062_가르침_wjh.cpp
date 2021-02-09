/*
 * 백준 1062 가르침
 * N개의 단어가 주어졌을 때 K개의 글자로만 이루어진 단어의 개수를 고르는 문제
 * 모든 단어는 anta로 시작하고 tica로 끝난다
 * N <= 50, 단어의 길이 <= 15
 * 먼저 a, n, t, i, c는 가르쳐야 한다
 * 즉, 26-5개의 글자 중에서 K-5개를 고르는 문제
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool learn[26];

int count(vector<string> &words)
{
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

int go(int index, int k, vector<string> &words)
{
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

int main()
{
	int n, m;
	cin >> n >> m;
	vector<string> words(n);
	for (int i = 0; i < n; i++) {
		cin >> words[i];
	}
	cout << go(0, m, words) << endl;
	return 0;
}