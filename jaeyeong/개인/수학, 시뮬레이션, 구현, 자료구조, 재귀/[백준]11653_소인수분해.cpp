using namespace std;
#include <iostream>

bool e[3200];

void era() {
	e[1] = true;
	for (int i = 2; i < 3200; i++) {
		if (e[i] == true) continue;
		for (int j = i * 2; j < 3200; j += i) {
			if (e[j] == true) continue;
			e[j] = true;
		}
	}
}

int main() {
	int n;
	cin >> n;
	era();
	if (n == 1) {
		return 0;
	}
	for (int i = 2; i < 3200; i++) {
		if (n == 1) break;
		if (e[i] == true) continue;
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1) cout << n << "\n";
	return 0;
}