#include <iostream>
#include <vector>
#include <cstring>
#define AMAX 100
#define NMAX 10001
using namespace std;

int main()
{
	int T, n;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> n;

		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		else if (n == 2) {
			cout << -1 << '\n';
			continue;
		}

		vector<vector<int>> a(n, vector<int>(n));

		vector<pair<int, int>> even;
		vector<pair<int, int>> odd;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ((i + j) % 2) // black cell
					odd.push_back({ i, j });
				else // white cell
					even.push_back({ i, j });
			}
		}

		int k = 1;

		// white cell부터 숫자를 채운다
		for (int i = 0; i < even.size(); i++) {
			a[even[i].first][even[i].second] = k++;
		}

		for (int i = 0; i < odd.size(); i++) {
			a[odd[i].first][odd[i].second] = k++;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << a[i][j] << ' ';
			}
			cout << '\n';
		}
	}


	return 0;
}