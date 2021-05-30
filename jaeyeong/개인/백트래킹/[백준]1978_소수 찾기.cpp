using namespace std;
#include <iostream>
#define MAX 1001

int n;
int e[MAX]; //0이면 소수, 1이면 소수 아님
void Eratos() {
	e[1] = 1;
	for (int i = 2; i < MAX; i++) {
		for (int j = i * 2; j < MAX; j+=i) {
			if (e[j] == 1) continue;
			else e[j] = 1;
		}
	}
}
int main() {
	int answer = 0;
	cin >> n;
	Eratos();
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (e[x] == 0) answer++;
	}
	cout << answer << '\n';
}