/*
k가 있을 때 6개 고르는 문제
k<12 사전 순으로 출력
전체 경우의 수는 2^12=4096
수를 고른다/고르지 않는다
*/
#include<iostream>
#include<vector>

using namespace std;
vector<int> lotto; // 함수가 고른 수 저장
void solve(vector<int>& a, int index, int cnt) {// a: 입력으로 주어진 수, index: 선택할지 말지 결정해야 하는 index, cnt: 현재까지 포함한 수의 개수
	/*
	1. 정답을 찾은 경우: cnt==6
	2. 불가능한 경우: 문제의 조건을 위배하는 선택 & 함수 호출을 해도 정답 x , 더이상 선택할수 없을 경우, index==a.size()
	3. 다음 경우 호출
		index 번째 수 선택: go(a,index+1, cnt+1)
		선택하지 않는 경우: go(a,index+1,cnt)
	*/
	if (cnt == 6) {//cnt==6 이면 출력
		for (int num : lotto)
			printf("%d ", num);
		printf("\n");
		return;
	}
	int n = a.size();
	if (n == index) return;
	lotto.push_back(a[index]);//선택
	solve(a, index + 1, cnt + 1);
	lotto.pop_back();//선택 x
	solve(a, index + 1, cnt);
}

int main() {
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		solve(a, 0, 0);
		cout << '\n';
	}
	return 0;
}
/*
6개 고르는 것을 사전 순으로
정렬하는 것이 없음
반드시 사전 순이 나오게 됨 이유는? 문제의 조건과 함수 구현에 답이있는데
문제 조건에 k 입력이 오름차순으로 입력
i번째를 선택하는 경우가 먼저 있기 때문에 = 작은 수를 선택하는게 먼저
그래서 사전순 처리 안해도 사전순으로 출력 가능함
*/