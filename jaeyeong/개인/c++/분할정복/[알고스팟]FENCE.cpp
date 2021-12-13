using namespace std;
#include <iostream>
#define MAX 20000

int fence[MAX];
int solve(int left, int right) {
	//판자가 하나밖에 없는 경우
	if (left == right) return fence[left];

	//[left,mid],[mid+1,right]의 두 구간으로 문제를 분할한다.
	int mid = (left + right) / 2;
	//분할한 문제를 각개 격파 (부분 문제 1,2)
	int ret = max(solve(left, mid), solve(mid + 1, right));
	//부분문제3: 두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(fence[lo], fence[hi]);
	//[mid, mid+1]만 포함하는 너비 2인 사각형을 고려한다.
	ret = max(ret, height * 2);
	//사각형이 입력 전체를 덮을 때까지 확장해 나간다.
	while (left < lo || hi < right) {
		//항상 높이가 더 높은 쪽으로 확장한다.
		if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])) {
			hi++;
			height = min(height, fence[hi]);
		}
		else {
			lo--;
			height = min(height, fence[lo]);
		}
		//확장한 후 사각형의 넓이
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main() {
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> fence[i];
		int ans = solve(0,n-1);
		cout << ans << '\n';
	}
}