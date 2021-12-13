using namespace std;
#include <iostream>
#include <queue>

long long board[1000000] = { 0 };

void initCase(long long n) {
	board[0] = 1 % 1000000009;
	board[1] = 2 % 1000000009;
	board[2] = 4 % 1000000009;
	for (int i = 3; i < n; i++)
		board[i] = (board[i - 1] + board[i - 2] + board[i - 3]) % 1000000009;
}
int main() {
	int n;
	long long max = -1, x;
	queue<long long int> q;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
		if (x > max) max = x;
	}

	initCase(max);

	for (int i = 0; i < n; i++) {
		cout << board[q.front()-1] << '\n';
		q.pop();
	}
}