using namespace std;
#include <iostream>
#define MAX 1000001

int m, n;
int e[MAX];
void Eratos() {
	e[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j += i) {
			if (e[j] == 1)continue;
			else e[j] = 1;
		}
	}
}

int main() {
	cin >> m >> n;
	Eratos();
	for (int i = m; i <= n; i++) {
		if (e[i] == 0) cout << i << '\n';
	}
}