using namespace std;
#include <iostream>
#define MAX 1000000

long long n, m;
long long trees[MAX];
long long maxV = -1;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		maxV = max(maxV, trees[i]);
	}
	long long left = 0, right = maxV;
	long long answer = 0;
	while (left <= right) {
		long long mid = (left + right) / 2; //자르는 높이
		long long sum = 0;
		for (int i = 0; i < n; i++)
			if (mid < trees[i])
				sum += (trees[i] - mid);
		if (sum >= m) {
			if (mid > answer)
				answer = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << answer << '\n';
	return 0;
}