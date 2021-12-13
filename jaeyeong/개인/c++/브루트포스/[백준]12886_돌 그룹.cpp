//https://yabmoons.tistory.com/133 ����Ǯ��. but ������ �ִµ�
//���� Ǯ�̴� �̰ͺ��� �� ���������� ����.
//�׷��� Ǯ�̹� ���� ������ �����߰�, �ڵ嵵 ������ ����ϰ� ���ͼ� ����
//visit ������ �����ϰ� Ǯ���� ��α׿��� ���� �����ߴ�.
using namespace std;
#include <iostream>
#include <queue>
#include <tuple>
#include <set>

set <tuple<int, int, int>> visit;
int selected[3][3] = { {0,1,2}, {0,2,1}, {1,2,0} }; //0,1��°�� ������ �� �׷�, 2��°�� ������ �� �׷�
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
			//������ �� �׷� ���� �׷��� �� ���� �ι谡 �� �� �ۿ� ����.
			//����� ���� ������ �ƴ� �����̶� ��.
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