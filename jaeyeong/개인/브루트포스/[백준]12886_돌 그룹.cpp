//https://yabmoons.tistory.com/133 유사풀이. but 문제가 있는듯
//백준 풀이는 이것보다 더 수학적으로 접근.
//그래도 풀이법 내가 셀프로 생각했고, 코드도 굉장히 깔끔하게 나와서 만족
//visit 개념을 유사하게 풀이한 블로그에서 보고 참고했다.
using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <set>

set <tuple<int, int, int>> visit;
int selected[3][3] = { {0,1,2}, {0,2,1}, {1,2,0} }; //0,1번째는 선택한 돌 그룹, 2번째는 나머지 돌 그룹
int arr[3];

bool bfs(int a1, int a2, int a3) {
	queue<tuple<int, int, int>> q;
	q.push(make_tuple(a1, a2, a3));
	visit.insert(make_tuple(a1, a2, a3));

	while (!q.empty()) {
		int x, y, z;
		tie(x, y, z) = q.front();
		if (x == y && x == z && y == z) return true;

		arr[0] = x;
		arr[1] = y;
		arr[2] = z;
		q.pop();

		for (int i = 0; i < 3; i++) {
			int bigger, smaller, left;
			//선택한 돌 그룹 작은 그룹의 돌 양이 두배가 될 수 밖에 없다.
			//경우의 수가 순열이 아닌 조합이란 말.
			if (arr[selected[i][0]] == arr[selected[i][1]]) continue;
			else if (arr[selected[i][0]] > arr[selected[i][1]]) {
				bigger = selected[i][0];
				smaller = selected[i][1];
			}
			else{
				bigger = selected[i][1];
				smaller = selected[i][0];
			}
			left = selected[i][2];
			arr[bigger] = arr[bigger] - arr[smaller];
			arr[smaller] *= 2;
	
			if (visit.find(make_tuple(arr[0],arr[1],arr[2])) == visit.end())
			{
				visit.insert(make_tuple(arr[0], arr[1], arr[2]));
				q.push(make_tuple(arr[0], arr[1], arr[2]));
			}
		}
	}
	return false;
}
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	cout<< bfs(a, b, c) << '\n';
}