#include<iostream>
#include<algorithm>
using namespace std;
const int inf = 10000000;
int t[20];
int p[20];
int d[20];
int n;
int go(int day) {
	if (day == n + 1)
		return 0;
	if (day > n + 1)
		return -inf;
	if (d[day] != -1)return d[day]; // 함수를 호출한 적이 있음
	int t1 = go(day + 1);//o
	int t2 = p[day] + go(day + t[day]);//x
	d[day] = max(t1, t2);
	return d[day];//go[day]의 returns =  day일 부터 얻을 수 있는 최대의 수열
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
		d[i] = -1;
	}
	cout << go(1) << '\n';
	return 0;
}
/*
다이나믹 문제임 퇴사 문제처럼 어떤 재귀함수의 호출이 이전호출하는 것의 영향을 받지 않을떄 라서
*/
/*cf*/
/*부분수열의 합
앞의 정보를 알아야 풀 수 있음 영향을 받음*/