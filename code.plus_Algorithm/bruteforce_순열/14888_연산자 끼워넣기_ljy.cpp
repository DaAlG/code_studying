/*
<연산자 끼워넣기>
N개의 수로 이루어진 수열과 N - 1개의 연산자가 있다.(2≤ N≤ 11)
이 때, 수와 수 사이에 연산자를 하나씩 끼워넣어서 만들 수 있는 수식 결과의 최대값과 최소값을 구하는 문제
수식의 계산은 연산자 우선순위를 무시하고 앞에서부터 진행한다
수의 순서는 바꿀 수 없다
(예제 입력 1)
2
5 6
0 0 1 0
(예제 입력 2)
3
3 4 5
1 0 1 0 // +개수 -개수 *개수 /개수
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc(vector<int>& a, vector<int>& b) {
	int n = a.size();
	int ans = a[0];
	for (int i = 1; i < n; i++) {
		if (b[i - 1] == 0) { // +
			ans = ans + a[i];
		}
		else if (b[i - 1] == 1) { // -
			ans = ans - a[i];
		}
		else if (b[i - 1] == 2) { // *
			ans = ans * a[i];
		}
		else if (b[i - 1] == 3) { // /
			ans = ans / a[i];
		}
	}
	return ans;
}
int main() {
	int n;
	cin >> n;

	/*수*/
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	/*연산자*/
	vector<int> b;
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int k = 0; k < cnt; k++) {
			b.push_back(i);
		}
	}

	sort(b.begin(), b.end());
	vector<int> result;
	do {
		int temp = calc(a, b);
		result.push_back(temp);
	} while (next_permutation(b.begin(), b.end()));

	auto ans = minmax_element(result.begin(), result.end());
	cout << *ans.second << '\n';
	cout << *ans.first << '\n';
	return 0;

}
