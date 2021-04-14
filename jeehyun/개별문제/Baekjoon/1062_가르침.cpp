/*
 * 브루트포스
 * 1062 가르침
 */

#include <iostream>
using namespace std;

int n, k;
string word[50];
bool alpha[26];

int go(int v, int cnt) 
{
	if (cnt == k) {
		int ret = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < word[i].size(); j++) {
				if (!alpha[word[i][j] - 'a']) {
					ret--;
					break;
				}
			}
		}
		return ret;
	}

	int ret = 0;
	for (int i = v; i < 26; i++) {
		if (!alpha[i]) {
			alpha[i] = true;
			ret = max(ret, go(i + 1, cnt + 1));
			alpha[i] = false;
		}
	}

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}

	if (k < 5) {
		cout << 0;
		return 0;
	}
	else if (k == 26) {
		cout << n;
		return 0;
	}

	alpha[0] = alpha['n' - 'a'] = alpha['t' - 'a'] = alpha['i' - 'a'] = alpha['c' - 'a'] = true;
	cout << go(0, 5);
	return 0;
}