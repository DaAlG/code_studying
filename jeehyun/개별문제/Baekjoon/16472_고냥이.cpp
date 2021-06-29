/*
 * 이분 탐색
 * 16472 고냥이
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	string s;
	cin >> n >> s;

	int left = 0;
	int right = 0;

	map<char, int> alpha;
	int answer = 0;

	while (right < s.size()) {
		if (alpha.size() <= n) {
			alpha[s[right++]]++;
			if (alpha.size() <= n)
				answer = max(answer, right - left);
		}
		else {
			while (alpha.size() > n) {
				alpha[s[left]]--;
				if (alpha[s[left]] == 0)
					alpha.erase(s[left]);
				left++;
			}
		}
	}
	cout << answer;
	return 0;
}