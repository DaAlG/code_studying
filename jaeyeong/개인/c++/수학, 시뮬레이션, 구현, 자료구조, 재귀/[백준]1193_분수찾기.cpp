using namespace std;
#include <iostream>

int main() {
	int parent = 1, child = 1;
	int odd = 1;//홀수번째 줄이면 child는 내림차순, parent는 오름차순
	int x;
	cin >> x;
	int cnt = 1;
	while (cnt != x) {
		if (odd % 2 == 1) {
			child--;
			parent++;
			if (child == 0) {
				odd++;
				child = 1;
				parent = odd;
			}
		}
		else {
			child++;
			parent--;
			if (parent == 0) {
				odd++;
				child = odd;
				parent = 1;
			}
		}
		cnt++;
	}
	cout << child << '/' << parent << '\n';
}