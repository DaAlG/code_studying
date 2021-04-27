/*
 * 문자열
 * 1181 단어 정렬
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<string> word;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(tmp);
	}

	sort(word.begin(), word.end(), cmp);
	word.erase(unique(word.begin(), word.end()), word.end());

	for (string s : word) {
		cout << s << '\n';
	}

	return 0;
}