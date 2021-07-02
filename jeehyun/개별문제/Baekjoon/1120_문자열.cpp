/*
 * 브루트포스
 * 1120 문자열
 */

#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string a, b;
	cin >> a >> b;

	int answer = 50;
	int diff = b.size() - a.size();

	for (int i = 0; i <= diff; i++) {
		int cnt = 0;
		for (int j = 0; j < a.size(); j++) {
			if (a[j] != b[i + j])
				cnt++;
		}
		answer = min(answer, cnt);
	}
	cout << answer;

	return 0;
}