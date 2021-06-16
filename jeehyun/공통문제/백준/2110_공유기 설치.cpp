#include <iostream>
#include <algorithm>
#define MAX 200000
using namespace std;

int x[MAX]; // 집 좌표

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);

	int left = 1; // 최소 거리
	int right = x[n - 1]; // 최대 거리
	int answer = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int cnt = 1;
		int now = 0;

		for (int i = 0; i < n; i++) {
			if (x[i] - x[now] >= mid) { // 거리가 mid 이상 차이날 경우 공유기 설치
				cnt++;
				now = i;
			}
		}

		// 설치한 공유기 수가 c보다 작다는 것은 거리가 너무 멀다는 것이므로 줄여준다
		if (cnt < c) {
			right = mid - 1;
		}
		else {
			// 공유기 사이의 최대 거리 갱신
			if (answer < mid)
				answer = mid;
			left = mid + 1;
		}
	}
	cout << answer;

	return 0;
}