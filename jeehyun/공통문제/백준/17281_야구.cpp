#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int res[51][10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			cin >> res[i][j];
		}
	}

	vector<int> batter;
	for (int i = 1; i <= 9; i++) batter.push_back(i);

	int answer = 0;
	do {
		// 1번 선수가 4번 타자가 아니면 타순을 다르게 정한다
		if (batter[3] != 1)
			continue;

		bool base[4];
		int cur = 0;
		int score = 0;
		
		for (int i = 1; i <= n; i++) {
			int out = 0;

			// 이닝이 바뀌면 베이스를 비워준다
			for (int j = 0; j < 4; j++)
				base[j] = 0;

			while (out < 3) {
				int next = batter[cur];
				base[0] = true;
				if (res[i][next] == 0) { // 아웃
					out++;
				}
				else { // 안타, 2루타, 3루타, 홈런
					for (int k = 3; k >= 0; k--) {
						if (base[k]) {
							if (k + res[i][next] > 3)
								score++;
							else
								base[k + res[i][next]] = true;
							base[k] = 0;
						}
					}
				}
				cur = (cur + 1) % 9; // 다음 타자
			}
		}
		answer = max(answer, score);
	} while (next_permutation(batter.begin(), batter.end()));

	cout << answer;

	return 0;
}