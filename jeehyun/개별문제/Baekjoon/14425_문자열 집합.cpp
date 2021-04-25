/*
 * 문자열 알고리즘
 * 14425 문자열 집합
 */

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> word;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		word.insert(tmp);
	}

	string s;
	int answer = 0;

	for (int i = 0; i < m; i++) {
		cin >> s;

		if (word.count(s))
			answer++;
	}
	cout << answer;

	return 0;
}