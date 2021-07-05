/*
 * 구현
 * 1713 후보 추천하기
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, k;
	cin >> n >> m;

	vector<int> frame;
	map<int, int> rec;

	for (int i = 0; i < m; i++) {
		cin >> k;
		rec[k]++;

		// 사진이 게시되지 않은 학생일 경우
		if (rec[k] == 1) {
			if (frame.size() >= n) {
				int minRec = 1000;
				int idx = 0;

				for (int j = 0; j < frame.size(); j++) {
					if (minRec > rec[frame[j]]) {
						minRec = rec[frame[j]];
						idx = j;
					}
				}
				rec.erase(frame[idx]);
				frame.erase(frame.begin() + idx);
				frame.push_back(k);
			}
			else {
				frame.push_back(k);
			}
		}
	}
	sort(frame.begin(), frame.end());

	for (int st : frame) {
		cout << st << ' ';
	}

	return 0;
}