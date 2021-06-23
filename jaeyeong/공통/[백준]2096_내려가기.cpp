using namespace std;
#include <iostream>
#include <cstring>
#define MAX 100000

int n;
int dp_max[3], dp_min[3], cur[3];

int main() {
	cin >> n;
	int a, b, c;
	cin >> dp_max[0] >> dp_max[1] >> dp_max[2];
	memcpy(dp_min, dp_max, sizeof(dp_min));
	for (int i = 1; i < n; i++) {
		cin >> cur[0] >> cur[1] >> cur[2];
		int t0 = dp_max[0], t1 = dp_max[1], t2 = dp_max[2];
		dp_max[0] = max(t0, t1) + cur[0];
		dp_max[1] = max(t0, max(t1, t2)) + cur[1];
		dp_max[2] = max(t1, t2) + cur[2];
		t0 = dp_min[0]; t1 = dp_min[1]; t2 = dp_min[2];
		dp_min[0] = min(t0, t1) + cur[0];
		dp_min[1] = min(t0, min(t1, t2)) + cur[1];
		dp_min[2] = min(t1, t2) + cur[2];
	}
	int ans_max = max(dp_max[0], max(dp_max[1], dp_max[2]));
	int ans_min = min(dp_min[0], min(dp_min[1], dp_min[2]));

	cout << ans_max << ' ' << ans_min << '\n';
	return 0;
}