using namespace std;
#include <iostream>

int n;
bool inRange(int start, int end) {
	return start <= n && n < end;
}
int main() {
	cin >> n;
	int start = 1, k = 1;
	int cnt = 1;
	while (!inRange(start, start + k)) {
		start += k;
		if (k == 1) k = 6;
		else k += 6;
		cnt++;
	}
	cout << cnt << '\n';
}