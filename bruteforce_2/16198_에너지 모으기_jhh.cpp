/*
n개의 에너지 구슬이 있고, i번째 에너지 구슬의 무게는 W[1],W[2],...,W[N]이다. N<=10
에너지를 모으는 방법은 다음과 같다
	1.에너지 구슬을 하나 고른다. 첫번째와 마지막은 고를 수 없다. 고른 구슬의 번호를 x라고 한다.
	2. x번째 구슬을 제거한다.
	3. W[x-1]*W[x+1]의 에너지를 모은다
	4. N을 1 감소시키고, 구슬의 번호를 다시 매긴다.

에너지를 모으는 전체 방법의 개수가 몇개가 있을까 = n개일때는 n-2개 고를 수 있음
=>(n-2)!=8!
*/
#include<iostream>
#include<vector>
using namespace std;
int go(vector<int>& a) {
	int n = a.size();
	if (n == 2) return 0; //2개는 에너지 모을 수 없음
	int ans = 0;
	for (int i = 1; i < n - 1; i++) { //지워야할 energy 찾기
		int energy = a[i - 1] * a[i + 1];
		vector<int> b(a);
		b.erase(b.begin() + i);
		energy += go(b);
		if (ans < energy) ans = energy;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i]; 
	cout << go(a) << '\n'; //배열 자체를 넘겨줌
	return 0;
}