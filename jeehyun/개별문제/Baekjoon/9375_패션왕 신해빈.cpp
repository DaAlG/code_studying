/*
 * 문자열
 * 9375 패션왕 신해빈
 */

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	while (T--) {
		cin >> n;

		vector<string> clothes;
		map<string, int> cnt;
		
		for (int i = 0; i < n; i++) {
			string cname, ctype;
			cin >> cname >> ctype;

			if (!cnt.count(ctype))
				clothes.push_back(ctype);
			cnt[ctype]++;
		}

		int answer = 1;
		for (string ctype : clothes) {
			answer *= cnt[ctype] + 1;
		}
		answer -= 1;

		cout << answer << '\n';
	}

	return 0;
}