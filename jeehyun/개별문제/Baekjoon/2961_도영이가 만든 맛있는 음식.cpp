/*
 * 브루트포스
 * 2961 도영이가 만든 맛있는 음식
 */

#include <iostream>
#include <vector>
#define INF 0x7fffffff
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int>> ingr(n);
	for (int i = 0; i < n; i++) {
		cin >> ingr[i].first >> ingr[i].second;
	}

	int answer = INF;
	for (int i = 1; i < (1 << n); i++) {
		int s = 1;
		int b = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				s *= ingr[j].first;
				b += ingr[j].second;
			}
		}
		answer = min(answer, abs(s - b));
	}

	cout << answer;
	return 0;
}