using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001

int home[MAX];
int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> home[i];
	sort(home, home+n);

	//이진탐색
	int low = 1;//최소거리
	int high = home[n - 1] - home[0]; //최대거리
	int cnt, tmp, mid, answer;
	while (low <= high) {
		cnt = 1;//두 공유기 사이의 거리를 최대로 하기 위해선 첫번째 집에 공유기가 설치되어야 한다.
		tmp = home[0];
		mid = (low + high) / 2;

		for (int i = 1; i < n; i++) {
			int d = home[i] - tmp;
			if (mid <= d) {
				cnt++;
				tmp = home[i];
			}
		}

		if (cnt >= c) { //계산된 공유기수 >=설치할 공유기수
			//공유기 간 간격 늘리기
			answer = mid;
			low = mid + 1;
		}
		else {
			//공유기 간의 간격 줄이기
			high = mid - 1;
		}
	}
	cout << answer << '\n';
}