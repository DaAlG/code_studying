#include <iostream>
using namespace std;

int n;
int t[16];
int p[16];
int answer = 0;

void solve(int cur, int pay) 
{
	if (cur > n) {
		if (answer < pay)
			answer = pay;
		return;
	}

	// 퇴사 전에 상담을 끝낼 수 있으면 상담을 한다
	if (cur + t[cur] <= n + 1)
		solve(cur + t[cur], pay + p[cur]);
	
	// 상담을 하지 않는다
	solve(cur + 1, pay);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}

	solve(1, 0);
	cout << answer;

	return 0;
}