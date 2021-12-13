using namespace std;
#include <iostream>
#define MAX 500001

int sum[MAX];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, h;
	int x;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (i % 2 == 0) { //석순
			sum[h - x + 1]++;
		}
		else { //종유석
			sum[1]++;
			sum[x + 1]--;
		}
	}
	int answer = -1;
	int cnt=0;
	for (int i = 1; i <= h; i++) {
		sum[i] += sum[i - 1];
		if(answer==-1 || sum[i]<answer){
			answer = sum[i];
			cnt = 1;
		}
		else if (sum[i] == answer) {
			cnt++;
		}
	}
	cout << answer << ' ' << cnt << '\n';
	return 0;
}