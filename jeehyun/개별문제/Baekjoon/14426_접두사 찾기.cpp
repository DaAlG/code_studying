/*
 * 문자열 알고리즘
 * 14426 접두사 찾기
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> word;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		word.push_back(tmp);
	}

	string prefix;
	int answer = 0;

	for (int i = 0; i < m; i++) {
		cin >> prefix;

		for (int j = 0; j < word.size(); j++) {
			if (word[j].find(prefix) == 0) {
				answer++;
				break;
			}
		}
	}
	cout << answer;

	return 0;
}