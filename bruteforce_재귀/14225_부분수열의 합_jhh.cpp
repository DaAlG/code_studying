/*
수열 s가 주어졌을 때, 수열 s의 부분 수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 문제
*/
#include<iostream>
using namespace std;
bool c[200 * 100000 + 10];
int a[20];
int n;
void go(int i, int sum) {
	if (i == n) {
		c[sum] = true;//합을 만들면 c[i]에 true : i를 만들 수 있을 때
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	go(0, 0);
	for (int i = 0;; i++) //가장 작은 수 부터 돌면서 false가 나오면 break;
		if (c[i] == false) {
			cout << i << '\n';
			break;
		}
	return 0;
}