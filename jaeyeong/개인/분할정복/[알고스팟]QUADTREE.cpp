using namespace std;
#include <iostream>
#include <string>

char board[20][20];
string s;

void solve(string::iterator& it, int y, int x, int size) {
	//���� �ϳ��� Ž���ϸ� iterator�� �Ű��ش�.
	//�� ������� ��� ĭ�� �����ϱ⿣ �޸𸮰� �����ϴ�.
	char head = *(it++);
	if (head == 'b' || head == 'w') {
		for (int dy = 0; dy < size; ++dy) {
			for (int dx = 0; dx < size; ++dx) {
				board[y + dy][x + dx] = head;
			}
		}
	}
	else {
		int half = size / 2;
		solve(it, y, x, half);
		solve(it, y, x + half, half);
		solve(it, y + half, x, half);
		solve(it, y + half, x + half, half);
	}
}

string reverse(string::iterator& it) {
	//�� ���ڸ� �˻��� ������ �ݺ��ڸ� �� ĭ ������ �ű��.
	char head = *(it++);
	if (head == 'w' || head == 'b') {
		return string(1, head);
	}
	string upperLeft = reverse(it);
	string upperRight = reverse(it);
	string lowerLeft = reverse(it);
	string lowerRight = reverse(it);

	return string("x") + lowerLeft + lowerRight + upperLeft + upperRight;
}
int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		cin >> s;
		string::iterator it = s.begin();
		cout << reverse(it) << '\n';
		//solve(it, 0, 0, s.length());
	}
}