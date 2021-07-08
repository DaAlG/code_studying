/*
 * 문자열
 * 1316 그룹 단어 체커
 */

#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int answer = 0;
	while (n--) {
		string word;
		cin >> word;

		set<char> alpha;
		bool possible = true;

		for (int i = 0; i < word.size(); i++) {
			if (alpha.count(word[i])) {
				possible = false;
				break;
			}
			alpha.insert(word[i]);
			while (i < word.size() && word[i + 1] == word[i]) i++;
		}

		if (possible)
			answer++;
	}
	cout << answer;

	return 0;
}