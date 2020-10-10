/*
연산자를 하나씩 끼워넣어서 만들 수 있는 수식 결과의 최대값과 최소값을 구하는 문제
수식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행한다.
수의 순서는 바꿀 수 없다.
모든 방법을 만들고 경우의 수 계산
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div) {//두 개의 값을 return 해야함: 최소&최대값
	/*
	a: 입력으로 주어진 수열
	index: 현재 계산해야하는 인덱스
	cur: index-1번째까지 계산한 결과
	plus,minus,mul,div: 사용할 수 있는 연산자의 개수
	*/
	int n = a.size();
	if (index == n) return make_pair(cur, cur);
	vector<pair<int, int>>res; 
	if (plus > 0) res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div)); //plus 한개 사용
	if (minus > 0) res.push_back(calc(a, index + 1, cur - a[index], plus, minus-1, mul, div));
	if (mul > 0) res.push_back(calc(a, index + 1, cur * a[index], plus , minus, mul-1, div));
	if (div > 0) res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div-1));
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first)
			ans.first = p.first;
		if (ans.second > p.second)
			ans.second = p.second;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	auto p = calc(a, 1, a[0], plus, minus, mul, div); //0번째 index 앞에는 연산자 넣을 수 없음 a[1]부터 계산하는 것 지정
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}