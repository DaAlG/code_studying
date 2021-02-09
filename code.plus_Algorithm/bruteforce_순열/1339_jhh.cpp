#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include <iostream>

using namespace std;
char alpha[256];

int calc(vector<string>& a, vector<char>& letters, vector<int>& d) {
	int m = letters.size();
	int sum = 0;

	for (int i = 0; i < m; i++)
		/*alpha에는 아스키 코드로 i의 값*/
		alpha[letters[i]] = d[i]; /*앞에서 정한 순서를 다 넣어줌*/
	for (string s : a) {
		int now = 0;
		for (char x : s) {
			now = now * alpha[x];
		}/*단어 1개의 값*/
		sum += now;
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	vector<string> a(n); /*단어*/
	vector<char> letters; /*알파벳*/
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (char x : a[i])
			letters.push_back(x);
	}

/*중복된 알파벳 제거*/
	sort(letters.begin(), letters.end());
	letters.erase(unique(letters.begin(), letters.end()), letters.end());
/*(9-m+1)부터 9까지 d에 넣어줌*/
	int m = letters.size();
	vector<int> d;
	for (int i = 9; i > 9 - m; i--) {
		d.push_back(i);
	}
/*next permutation 하기 위한 sort*/
	sort(d.begin(), d.end());
	int ans = 0;
	do {
		int now = calc(a, letters, d);
		if (ans < now) ans = now;
	} while (next_permutation(d.begin(), d.end()));

	cout << ans << '\n';
	
	return 0;
}
