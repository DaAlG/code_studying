/*
 * 정렬
 * 1205 등수 구하기
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, score, p;
	cin >> n >> score >> p;

	vector<int> scores(n);
	for (int i = 0; i < n; i++) {
		cin >> scores[i];
	}
	scores.push_back(score);

	sort(scores.begin(), scores.end(), greater<int>());

	int rank = 0;
	int idx;

	for (idx = 0; idx < scores.size(); idx++) {
		rank = idx + 1; // 인덱스 + 1이 등수

		// 동일한 점수가 있다면 마지막 점수가 유진의 점수
		while (idx + 1 < scores.size() && scores[idx + 1] == scores[idx])
			idx++;

		if (scores[idx] == score)
			break;
	}

	// 랭킹 리스트에 올라갈 수 있으면 등수 출력
	if (idx < p) 
		cout << rank;
	else
		cout << -1;


	return 0;
}