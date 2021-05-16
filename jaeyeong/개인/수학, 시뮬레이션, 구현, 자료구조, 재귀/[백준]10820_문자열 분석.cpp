using namespace std;
#include <iostream>
#include <string>

int main() {
	char x;
	int i = 0;
	int small = 0, big = 1, num = 2, vac = 3;
	int arr[4] = { 0 };
	while (1) {
		x=getchar();
		if (x == EOF) break;
		else if (x == '\n') {
			i++;
			for (int j = 0; j < 4; j++) {
				cout << arr[j] << ' ';
				arr[j] = 0;
			}
			cout << '\n';
			continue;
		}
		else if ('a' <= x && x <= 'z') arr[small]++;
		else if ('A' <= x && x <= 'Z') arr[big]++;
		else if ('0' <= x && x <= '9') arr[num]++;
		else arr[vac]++;
	}
	return 0;
}