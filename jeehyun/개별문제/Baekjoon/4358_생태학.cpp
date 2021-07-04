/*
 * 자료구조
 * 4358 생태학
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> spc;
	vector<pair<string, float>> trees;
	string s;
	int total = 0;

	while (getline(cin, s)) {
		if (!spc.count(s)) {
			trees.push_back({ s, 0 });
		}
		spc[s]++;
		total++;
	}
	sort(trees.begin(), trees.end());

	// 소수점 자리를 4자리로 고정
	cout << fixed;
	cout.precision(4);

	for (int i = 0; i < trees.size(); i++) {
		trees[i].second = (float)spc[trees[i].first] / total * 100;
		cout << trees[i].first << ' ' << trees[i].second << '\n';
	}

	return 0;
}