/*
<단어수학>
단어 수학은 0부터 9까지의 수를 알파벳 하나로 나타낸 것이다
N개의 단어를 수로 바꾼 다음에, 합의 최대값을 구하는 문제이다(1≤ N≤10)
예를 들어, GCF + ACDEB가 문제라고 한다면
만들 수 있는 합의 최대값은 99437이다(A = 9, B = 4, C = 8, D = 6, E = 5, F = 3, G = 7)
서로 다른 알파벳의 개수는 10개이다

input:
2
GCF
ACDEB
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

char alpha[256];

int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
	int m = letters.size();
	int sum = 0;
	for (int i = 0; i < m; i++) {
		alpha[letters[i]] = d[i];
	}
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * 10 + alpha[x];
		}
		sum += now;
	}
	return sum;
}
int main() {
	int n;
	cin >> n;
	vector<string> a(n);	//단어
	vector<char> letters;	//알파벳

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char x : a[i]) {
			letters.push_back(x);
		}
	}

	//중복제거
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());

	int m = letters.size();
	vector<int> d;
	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i);
	}
	sort(d.begin(), d.end());

	int ans = 0;

	do {
		int now = calc(a, letters, d);
		if (ans < now) {
			ans = now;
		}
	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';
	return 0;
}