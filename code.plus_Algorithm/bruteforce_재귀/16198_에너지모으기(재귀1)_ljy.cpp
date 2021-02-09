/*
에너지 모으기

i번째 에너지 구슬의 무게는 W(i)인 n개의 에너지구슬이 일렬로 놓여져 있다.
1. 일렬로 놓인 에너지구슬 중 첫 번째와 마지막 에너지 구슬을 제외한 하나를 고른다.(고른 번호를 x라고 하자)
2. x번째 에너지 구슬을 제거하고
3. W[x-1]*W[x+1]만큼의 에너지를 모은다.
4. N을 1 감소시키고 에너지 구슬을 1번부터 N번까지로 다시 번호를 매긴다. (첫 구슬을 1로 하여..)

//강사왈: 총 경우의 수가 (n-2)! 이니 다 돌려봐도 시간내로 나올듯

(입력)
첫째 줄: 에너지 구슬의 개수 N(3<=N<=10)
둘째 줄: 에너지 구슬의 무게 W(1), W(2)... W(n)을 공백으로 구분해 주어짐(무게는 1이상 1,000 이하)

(출력)
첫째 줄에 모을 수 있는 에너지의 최대값을 출력한다.

(입력1)
4
1 2 3 4
(출력1)
12
(입력2)
5
100 2 1 3 100
(출력2)
10400
*/

#include <iostream>
#include <vector>
using namespace std;

int go(vector<int>& a) {
	int n = a.size();
	if (n == 2) return 0;
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		//erase 와방 편리하다 죽인다
		b.erase(b.begin() + i);
		energy += go(b);
		if (ans < energy) {
			ans = energy;
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << go(a) << '\n';
	return 0;
}