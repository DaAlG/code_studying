/*
n+1이 되는 날 퇴사를 하려고 한다.
남은 n일 동안 최대한 많은 상담을 하려고 한다.
하루에 하나의 상담을 할 수 있고 i일에 상담을 하면, t[i]일이 걸리고 p[i]원을 번다
*/
#include<iostream>
using namespace std;
const int inf = -10000000;
int t[21];
int p[21];
int n;
int ans = 0;
void go(int day, int sum) {
	//누적해 나가면서 다음 수 호출
	if (day == n + 1) {
		if (ans < sum)ans = sum;
		return;
	}
	if (day > n + 1)
		return;
	go(day + 1, sum);
	go(day + t[day], sum + p[day]);
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> t[i] >> p[i];
	go(1, 0);
	cout << ans << '\n';
	return 0;
}
/*앞의 코드를 return 값을 이용하게 수정하면 다음과 같이 수정할 수 있다 day일로 부터 얻을 수 있는
*/
/*의미있는 방법 : 최대 수익이 나오는 방법
앞부분에서 가장 최대인 친구가 최대가 됨
1~3일 까지 적절히 상담을 진행하고 4일이 된 후에 4~6일 동안 얻을 수 있는 최대 수익과 같다.
영향을 미치지 않는다면 얻을 수 있는 방법 7*/