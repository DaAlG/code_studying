/*
서로 다른 N개의 정수로 이루어진 수열이 있을 때, 크기ㅏ 양수인 부분 수열 중에서 그 수열의 원소를 다 더한 값이 S가 되는 경우의 수를 구하는 문제
부분 수열의 개수=2^n
크기가 양수인 부분수열 = 2^n-1
모든 부분 수열을 구해보고 s와 같은 경우가 있는지 없는지 check
o(2^n)
*/
#include<iostream>
using namespace std;
int a[20];
int n, m;
int ans = 0;
/*
go(index, sum)
index : 부분 수열에 포함할지 말지 결정해야하는 인덱스
sum: 현재까지 부분수열의 합
1. 정답을 찾은 경우: index ==n && sum ==m
2. 불가능한 경우: index == n && sum!=m
3. 다음경우:
	index 번째를 부분수열에 추가: go(index+1,sum+a[i])
	index 번째를 부분수열에 추가하지 않음: go(index+1,sum)))
*/
void go(int i, int sum) {
	if (i == n) {
		if (sum == m)
			ans += 1;
		return;
	}
	go(i + 1, sum + a[i]);
	go(i + 1, sum);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	go(0, 0);
	if (m == 0) ans -= 1;//꼭 있어야 함 크기가 양수인 부분수열도 재귀함수에서는 가능하므로 합이 0이 됨 (전부 선택하지 않을 경우)
	cout << ans << '\n';
	return 0;
}