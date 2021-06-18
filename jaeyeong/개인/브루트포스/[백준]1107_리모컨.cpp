using namespace std;
#include <iostream>
#define MAX 1000000

bool broken[10];

int check(int n) { //n으로 한번에 이동할 수 있을 때만 len 반환
	if (n == 0) {
		if (broken[0]) return 0;
		else return 1;
	}
	int len = 0;
	while (n > 0) {
		if (broken[n % 10]) return 0;
		n = n / 10;
		len ++;
	}
	return len; //리모콘 누른 횟수
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k;
		cin >> k;
		broken[k] = true;
	}
	int answer = abs(n - 100);
	for (int i = 0; i <= MAX; i++) {
		int c = i;
		int len = check(c);
		if (len > 0) {
			int press = abs(c - n);
			answer = min(answer, press + len);
		}
	}
	cout << answer << '\n';
}