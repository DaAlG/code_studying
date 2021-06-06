/*
 * 문자열
 * 4659 비밀번호 발음하기
 */

#include <iostream>

using namespace std;

bool isVowel(char ch)
{
	return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

bool acceptable(string s)
{
	bool vowel = false; // 모음
	
	for (int i = 0; i < s.size(); i++) {
		int cnt = 0;

		if (isVowel(s[i])) {
			vowel = true;
			for (int j = i - 2; j >= 0 && j <= i; j++) {
				if (isVowel(s[j]))
					cnt++;
			}
		}
		else {
			for (int j = i - 2; j >= 0 && j <= i; j++) {
				if (!isVowel(s[j]))
					cnt++;
			}
		}

		// 모음이 3개 또는 자음이 3개 연속으로 오면 안 된다
		if (cnt == 3)
			return false;

		// ee, oo 외에 같은 글자가 연속적으로 두 번 나오면 안됨
		if (i - 1 >= 0 && s[i - 1] == s[i]) {
			if (s[i] != 'e' && s[i] != 'o')
				return false;
		}
	}

	// 모음 하나를 반드시 포함해야 한다
	if (vowel)
		return true;
	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;

	while (cin >> s) {
		if (s == "end")
			break;

		cout << "<" + s + "> is ";
		if (acceptable(s))
			cout << "acceptable.\n";
		else
			cout << "not acceptable.\n";
	}

	return 0;
}