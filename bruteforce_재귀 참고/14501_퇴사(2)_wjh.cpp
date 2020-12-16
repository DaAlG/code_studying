#include <iostream>
#include <algorithm>
using namespace std;

const int inf = 100000000;
int t[20];
int p[20];
int d[20];
int n;

// day일에 있는 상담을 할지 말지 결정
int go(int day) {
	if (day == n + 1) {
		return 0;
	}

	// 불가능한 경우
	if (day > n + 1) {
		return -inf;
	}

	if (d[day] != -1) {
		return d[day];
	}

	// 상담을 하지 않는다
	int t1 = go(day + 1);

	// 상담을 한다
	int t2 = p[day] + go(day + t[day]);

	//day일로부터 얻을 수 최대 수익
	d[day] = max(t1, t2);

	return d[day];
}

int main() {
	// C 표준 stream과 C++ 표준 stream의 동기화를 끊음 -> 실행속도 향상
	ios_base::sync_with_stdio(false);
	// cin을 cout으로부터 untie
	cin.tie(nullptr);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		d[i] = -1;
	}
	cout << go(1) << endl;
	return 0;
}