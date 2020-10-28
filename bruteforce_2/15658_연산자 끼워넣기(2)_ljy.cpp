/*
<연산자 끼워넣기>
N개의 수로 이루어진 수열과 N-1개 "이상"의 연산자가 있다 (2<=N<=11)
이 때, 수와 수 사이에 연산자를 하나씩 끼워넣어서 만들 수 있는 수식 결과의 최대값과 최솟값을 구하라.

*수식의 계산은 앞에서부터!(연산자 순위 무시)
*수의 순서는 바꿀 수 없다

(예제 입력 1)
2
5 6
1 1 1 1
(예제 출력 1)
30 //만들 수 있는 식의 최댓값
-1 //만들 수 있는 식의 최솟값
*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> calc(vector<int> &a, int index, int cur, int plus, int minus, int mul, int div) {
	int n = a.size();
	if (index == n) {
		return make_pair(cur, cur);
	}
	vector<pair<int, int>> res;
	if (plus > 0) {
		res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div));
	}
	if (minus > 0) {
		res.push_back(calc(a, index + 1, cur - a[index], plus, minus - 1, mul, div));
	}
	if (mul > 0) {
		res.push_back(calc(a, index + 1, cur*a[index], plus, minus, mul - 1, div));
	}
	if (div > 0) {
		res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div - 1));
	}
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first) {
			ans.first = p.first;
		}
		if (ans.second > p.second) {
			ans.second = p.second;
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	auto p = calc(a, 1, a[0], plus, minus, mul, div);
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}