/*
 * 그리디
 * 1946 신입 사원
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n, a, b;
		cin >> n;

		vector<pair<int, int>> grade(n);
		for (int i = 0; i < n; i++) {
			// 서류심사 성적, 면접시험 성적
			cin >> grade[i].first >> grade[i].second;
		}

		// 오름차순 정렬
		sort(grade.begin(), grade.end());

		int answer = 0;
		int min = 1000001; // 면접시험 성적

		for (int i = 0; i < n; i++) {
			// 기존의 면접시험 성적보다 높은 성적인 사람 채용
			if (min > grade[i].second) {
				answer++;
				// 면접시험 성적 업데이트
				min = grade[i].second;
			}
		}
		cout << answer << '\n';
	}

	return 0;
}