using namespace std;
#include <iostream>
#include <vector>
#include <stack>

int n;
vector<pair<int, int>> answer;

//from에 꽂혀있는 n개의 원반을 by를 거쳐 to로 이동한다.
void hanoi(int n, int from, int by, int to) {	
	//이동할 개수가 1개라면
	if (n == 1) {
		answer.push_back(make_pair(from, to));
		return;
	}
	else {
		//step 1: num-1개를 A에서 B로 이동
		hanoi(n - 1, from, to, by);
		//step 2: 1개를 A에서 C로 이동
		answer.push_back(make_pair(from, to));
		//step 3: num-1개를 B에서 C로 이동
		hanoi(n - 1, by, from, to);
	}

}
int main() {
	cin >> n;
	
	hanoi(n, 1, 2, 3);
	cout << answer.size()<<'\n';
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}
}
