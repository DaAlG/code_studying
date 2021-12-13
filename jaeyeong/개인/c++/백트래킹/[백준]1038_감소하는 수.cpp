using namespace std;
#include <iostream>
#include <algorithm>

long long n, arr[1024], aidx = 0;

void solve(long long num) {
	long long val = num % 10, cur = num * 10;
	for (int i = 0; i < val; i++) {
		arr[aidx++] = cur + i;
		solve(cur+i);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i <= 9; i++) {
		arr[aidx++] = i;
		solve(i);
	}
	
	if (n < aidx) {
		sort(arr, arr + aidx);
		cout << arr[n] << '\n';
	}
	else cout << "-1\n";
	return 0;
}