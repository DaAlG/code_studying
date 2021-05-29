/*
 * 그리디
 * 1700 멀티탭 스케줄링
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int arr[MAX];
int cnt[MAX];
bool plugged[MAX];

int main()
{
	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= k; i++) {
		cin >> arr[i];
		cnt[arr[i]]++;
	}

	vector<int> tap;
	int answer = 0;

	for (int i = 1; i <= k; i++) {
		cnt[arr[i]]--;

		if (plugged[arr[i]]) continue;

		// 꽂을 자리가 없는 경우
		if (tap.size() >= n) {
			answer++;

			int minUse = 100;
			int idx = 0;
			for (int j = 0; j < tap.size(); j++) {
				if (minUse > cnt[tap[j]]) {
					minUse = cnt[tap[j]];
					idx = j;
				}
			}

			if (minUse == 0) {
				plugged[tap[idx]] = false;
				tap.erase(tap.begin() + idx);
			}
			else { // 가장 마지막에 쓰는 플러그를 빼준다
				int lastUse = 0;
				int lastIdx = 0;

				for (int j = 0; j < tap.size(); j++) {
					for (int m = i + 1; m <= k; m++) {
						if (arr[m] == tap[j]) {
							if (lastUse < m) {
								lastUse = m;
								lastIdx = j;
							}
							break;
						}
					}
				}

				plugged[tap[lastIdx]] = false;
				tap.erase(tap.begin() + lastIdx);
			}
		}

		// 남는 자리에 플러그를 꽂는다
		plugged[arr[i]] = true;
		tap.push_back(arr[i]);
	}
	cout << answer;
	return 0;
}