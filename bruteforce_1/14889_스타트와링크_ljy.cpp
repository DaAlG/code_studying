/*
<스타트와 링크>
N명을 N/2명씩 두 팀으로 나누려고 한다. (4≤N≤20,N은 짝수)
두 팀의 능력치를 구한 다음, 차이의 최소값을 구하는 문제
S[i][j]=i번 사람과 j번 사람이 같은 팀에 속했을 때, 팀에 더해지는 능력치
팀의 능력치: 팀에 속한 모든 쌍의 S[i][j]의 합
(출력)
첫째 줄에 스타트 팀과 링크 팀의 능력치의 차이를 최솟값을 출력한다.
(예제 입력 1)
4
0 1 2 3
4 0 5 6
7 1 0 2
3 4 5 0
(예제 입력 2)
6
0 1 2 3 4 5
1 0 2 3 4 5
1 2 0 3 4 5
1 2 3 0 4 5
1 2 3 4 0 5
1 2 3 4 5 0
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	vector<int> b(n);

	for (int i = 0; i < n / 2; i++) {
		b[i] = 1;
	}
	sort(b.begin(), b.end());
	int ans = 2147483647;
	do {
		vector<int> first, second;
		for (int i = 0; i < n; i++) {
			if (b[i] == 0) {
				first.push_back(i);
			}
			else {
				second.push_back(i);
			}
		}
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue;
				one += a[first[i]][first[j]];
				two += a[second[i]][second[j]];
			}
		}
		int diff = one - two;
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(b.begin(), b.end()));

	cout << ans << '\n';
	return 0;
}