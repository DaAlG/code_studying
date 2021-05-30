/*
 * 이분탐색
 * 3649 로봇 프로젝트
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x, n;

	while (cin >> x >> n) {
		// 센티미터 -> 나노미터
		x *= 10000000;

		vector<int> lego(n);
		for (int i = 0; i < n; i++) {
			cin >> lego[i];
		}

		// 오름차순으로 정렬
		sort(lego.begin(), lego.end());

		int left = 0;
		int right = n - 1;
		bool possible = false;

		// 투 포인터
		while (left < right) {
			int sum = lego[left] + lego[right];

			if (sum == x) {
				possible = true;
				cout << "yes " << lego[left] << ' ' << lego[right] << '\n';
				break;
			}
			else if (sum < x) {
				left++;
			}
			else if (sum > x) {
				right--;
			}
		}

		// 구멍을 완벽하게 막을 수 있는 두 조각이 없다
		if (!possible)
			cout << "danger\n";
	}

	return 0;
}