/*
 * 문자열
 * 1764 듣보잡
 */

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> name;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		name.insert(s);
	}

	vector<string> answer;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		
		if (name.find(s) != name.end()) {
			answer.push_back(s);
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (auto s : answer) {
		cout << s << '\n';
	}

	return 0;
}