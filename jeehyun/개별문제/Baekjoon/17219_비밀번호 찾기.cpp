/*
 * 자료구조
 * 17219 비밀번호 찾기
 */

#include <iostream>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	map<string, string> pw; // 사이트, 비밀번호

	for (int i = 0; i < n; i++) {
		string ad, p;
		cin >> ad >> p;
		pw[ad] = p;
	}

	for (int i = 0; i < m; i++) {
		string ad;
		cin >> ad;
		cout << pw[ad] << '\n';
	}

	return 0;
}