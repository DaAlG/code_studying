using namespace std;
#include <iostream>
#include <string>

char board[20][20];
string s;

void solve(string::iterator& it, int y, int x, int size) {
	//글자 하나를 탐색하면 iterator을 옮겨준다.
	//이 방법으로 모든 칸을 저장하기엔 메모리가 부족하다.
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
	//한 글자를 검사할 때마다 반복자를 한 칸 앞으로 옮긴다.
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