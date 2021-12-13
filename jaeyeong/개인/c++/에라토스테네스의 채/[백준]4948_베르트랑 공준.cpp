using namespace std;
#include <iostream>
#define MAX 246913

int e[MAX];

void Eratos() {
	e[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			if (e[j] == 1) continue;
			else e[j] = 1;
		}
	}
}
int main() {
	int c;
	cin >> c;
	Eratos();
	while (c != 0) {
		int cnt = 0;
		for (int i = c+1; i <= 2 * c; i++)
			if (e[i] == 0) cnt++;
		cout << cnt << '\n';
		cin >> c;
	}
	return 0;
}