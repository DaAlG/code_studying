/* 
 * 브루트포스
 * 1339 단어 수학
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int alpha[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	string word;
	for (int i = 0; i < n; i++) {
		cin >> word;
		int mult = 1;
		for (int j = word.size() - 1; j >= 0; j--) {
			alpha[word[j] - 'A'] += mult;
			mult *= 10;
		}
	}
	sort(alpha, alpha + 26, greater<int>());

	int answer = 0;
	int num = 9;
	for (int i = 0; i < 26; i++) {
		if (alpha[i] != 0) {
			answer += alpha[i] * num;
			num--;
		}
	}
	cout << answer;
	return 0;
}