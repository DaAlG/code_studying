/*
 * 정렬
 * 2822 점수 계산
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<pair<int, int>> score;
	for (int i = 1; i <= 8; i++) {
		int tmp;
		cin >> tmp;
		score.push_back({ tmp, i });
	}

	sort(score.begin(), score.end(), cmp);

	vector<int> p;
	int sum = 0;

	for (int i = 0; i < 5; i++) {
		sum += score[i].first;
		p.push_back(score[i].second);
	}
	sort(p.begin(), p.end());

	cout << sum << '\n';
	for (int i = 0; i < 5; i++) {
		cout << p[i] << ' ';
	}
	return 0;
}