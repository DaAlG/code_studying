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
		while (!q.empty()) { //q�� ������� ������
			pair<int, int> t = q.back(); //���� �������� ����� ����
			if (t.second >= a) q.pop_back(); //�̹� ������ ũ�� ���ֱ�
			else break;//�ƴ϶�� ������
		}
		q.push_back(make_pair(i, a));//���� ����, �̹��� ���� �� �ֱ�
		pair<int, int> t = q.front();//q�� �ִ� ���� ���� ���� ���°�
		if (t.first == i - l) q.pop_front(), t = q.front();//�̹� ���� ���� ���� ���̶�� pop. t ������Ʈ
		cout << t.second << ' ';
	}
}