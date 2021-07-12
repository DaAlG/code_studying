using namespace std;
#include <iostream>
#include <deque>

int n, l, a;
deque<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		cin >> a;
		while (!q.empty()) { //q가 비어있지 않으면
			pair<int, int> t = q.back(); //가장 마지막에 덜어온 값이
			if (t.second >= a) q.pop_back(); //이번 값보다 크면 없애기
			else break;//아니라면 스루해
		}
		q.push_back(make_pair(i, a));//들어온 차례, 이번에 들어온 값 넣기
		pair<int, int> t = q.front();//q에 있는 값중 가장 먼저 들어온값
		if (t.first == i - l) q.pop_front(), t = q.front();//이번 차례 포용 범위 밖이라면 pop. t 업데이트
		cout << t.second << ' ';
	}
}