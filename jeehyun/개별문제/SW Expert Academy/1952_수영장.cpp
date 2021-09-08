#include <iostream>
using namespace std;

int cost[4];
int days[12];
int answer;

void go(int n, int sum)
{
	if (n >= 12) {
		answer = min(answer, sum);
		return;
	}

	if (sum >= answer) return;
	
	if (days[n] == 0) {
		go(n + 1, sum);
	}
	else {
		// 1�� �̿�� ���� ���
		go(n + 1, sum + days[n] * cost[0]);

		// 1�� �̿�� ���� ���
		go(n + 1, sum + cost[1]);

		// 3�� �̿�� ���� ���
		go(n + 3, sum + cost[2]);
	}

}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		for (int i = 0; i < 4; i++) cin >> cost[i];
		for (int i = 0; i < 12; i++) cin >> days[i];

		answer = cost[3];
		go(0, 0);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}