/*
수열 s 가 주어졌을 때, 수열 s 의 부분수열의 합으로 나올 수 없는 가장 작은 자연수를 구하는 뭄ㄴ제
n<=20, 수<=10만

*/
#include<iostream>
using namespace std;
bool c[20 * 100000 + 10]; //c[i]==true 수 i 를 만들 수 있다. 모든 수가 10만이라면 20*10만번째도 만들 수 있으므로 20*10만+1 index 사용할 수 있게
int a[20];
int n;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) sum += a[j];
		}
		c[sum] = true;
	}
	for (int i = 1;; i++) {
		if (c[i] == false) {//만들 수 없다는 것을 의미
			cout << i << '\n';
			break;
		}
	}
	return 0;
}