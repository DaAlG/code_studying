/*
연산자 끼워넣기 1과의 차이점 : n-1개 이상의 연산자가 있다
몇개의 연산자가 있을 지 모름
더 많은 경우의 수 가능
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div) {
	int n = a.size();
	if (index == n) return make_pair(cur, cur);
	vector<pair<int, int>> res;
	if (plus > 0) res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	if (minus > 0) res.push_back(calc(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	if (mul > 0) res.push_back(calc(a, index + 1, cur * a[index], plus, minus, mul - 1, div));
	if (div > 0) res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div - 1));
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first) ans.first = p.first;
		if (ans.second > p.second) ans.second = p.second;
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
	auto p = calc(a, 1, a[0], plus, minus, mul, div);
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}
