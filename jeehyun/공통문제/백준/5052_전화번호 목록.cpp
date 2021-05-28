#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		vector<string> pnum(n);		
		for (int i = 0; i < n; i++) {
			cin >> pnum[i];
		}

		sort(pnum.begin(), pnum.end());

		bool check = true;
		for (int i = 1; i < n; i++) {
			if (pnum[i - 1] == pnum[i].substr(0, pnum[i - 1].size())) {
				check = false;
				break;
			}
		}

		if (check) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}