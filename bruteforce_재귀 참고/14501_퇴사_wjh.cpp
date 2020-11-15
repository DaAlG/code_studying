#include <iostream>

using namespace std;

const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;

// day일에 있는 상담을 할지 말지 결정
// 지금까지 얻은 수익은 sum
void go(int day, int sum) {
	// day일부터 얻을 수 있는 최대 수익
	if (day == n + 1) {
		if (ans < sum) ans = sum;
		return;
	}

	// 불가능한 경우
	if (day > n + 1) {
		return;
	}

	// 상담을 하지 않는다
	go(day + 1, sum);

	// 상담을 한다
	go(day + t[day], sum + p[day]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	go(1, 0);
	cout << ans << endl;
	return 0;
}