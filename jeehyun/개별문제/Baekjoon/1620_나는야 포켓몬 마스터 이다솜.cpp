/*
 * 자료구조
 * 1620 나는야 포켓몬 마스터 이다솜
 */

#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<string> pocketmon(n + 1);
	map<string, int> num;

	for (int i = 1; i <= n; i++) {
		cin >> pocketmon[i];
		num[pocketmon[i]] = i;
	}

	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;

		if (s[0] >= '0' && s[0] <= '9')
			cout << pocketmon[stoi(s)] << '\n';
		else
			cout << num[s] << '\n';
	}
	return 0;
}