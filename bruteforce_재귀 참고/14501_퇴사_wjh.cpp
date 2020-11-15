#include <iostream>

using namespace std;

const int inf = -100000000;
int t[21];
int p[21];
int n;
int ans = 0;

// day�Ͽ� �ִ� ����� ���� ���� ����
// ���ݱ��� ���� ������ sum
void go(int day, int sum) {
	// day�Ϻ��� ���� �� �ִ� �ִ� ����
	if (day == n + 1) {
		if (ans < sum) ans = sum;
		return;
	}

	// �Ұ����� ���
	if (day > n + 1) {
		return;
	}

	// ����� ���� �ʴ´�
	go(day + 1, sum);

	// ����� �Ѵ�
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