using namespace std;
#include <iostream>
#define MAX 4000000

int n, k;
int e[MAX];
void Eratos() {
	e[1] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = i * 2; j <= n; j += i) {
			if (e[j] == 1) continue;
			else e[j] = 1;
		}
	}
}

int next(int k) {
	for (int i = k + 1; i < MAX; i++)
		if (e[i] == 0) return i;
}

int main() {
	cin >> n;
	Eratos();
	int start = 2, end = 2, answer = 0;
	int sum = 0;
	while (end <= n+1) {
		if (sum >= n) {
			sum -= start;
			start = next(start);
		}
		else if (sum < n) {
			sum += end;
			end = next(end);
		}
		if (sum == n) answer++;
	}
	cout << answer << '\n';
}