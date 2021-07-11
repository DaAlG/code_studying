/*
 * 투 포인터
 * 20366 같이 눈사람 만들래?
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h[601];

struct Snowman {
	int idx1;
	int idx2;
	int height;
};

bool cmp(Snowman a, Snowman b)
{
	return a.height < b.height;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> h[i];
	sort(h, h + n);

	int answer = 2000000000; // 두 눈사람의 키 차이 중 최솟값

	vector<Snowman> snowman;

	// 가능한 모든 눈사람 만들기
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			snowman.push_back({ i, j, h[i] + h[j] });
		}
	}
	sort(snowman.begin(), snowman.end(), cmp);

	for (int i = 0; i < snowman.size() - 1; i++) {
		for (int j = i + 1; j < snowman.size(); j++) {
			if (snowman[j].idx1 != snowman[i].idx1 && snowman[j].idx1 != snowman[i].idx2
				&& snowman[j].idx2 != snowman[i].idx1 && snowman[j].idx2 != snowman[i].idx2) {
				answer = min(answer, snowman[j].height - snowman[i].height);
				break;
			}
		}
	}

	/* 투 포인터
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int s1 = h[i] + h[j];
			int left = i;
			int right = n - 1;

			while (1) {
				while (left == i || left == j) left++;
				while (right == i || right == j) right--;

				if (left >= right)
					break;

				int s2 = h[left] + h[right];
				if (s1 < s2) {
					answer = min(answer, s2 - s1);
					right--;
				}
				else {
					answer = min(answer, s1 - s2);
					left++;
				}
			}
		}
	}*/


	cout << answer;
	return 0;
}