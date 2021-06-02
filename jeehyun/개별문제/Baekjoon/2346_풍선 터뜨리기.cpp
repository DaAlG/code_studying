/*
 * 자료구조
 * 2346 풍선 터뜨리기
 */

#include <iostream>
#define MAX 1002
using namespace std;

int balloon[MAX];
bool burst[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> balloon[i];
	}

	int k = n - 1;
	int next = 1;

	cout << next << ' ';
	while (k) {
		k--;
		int cnt = balloon[next];
		burst[next] = true;

		if (cnt < 0) { // 왼쪽으로 이동
			for (int i = 0; i < abs(cnt); i++) {
				next--;

				if (next < 1) next = n;

				// 이미 터진 풍선은 뺀다
				while (burst[next]) {
					next--;
					if (next < 1)
						next = n;
				}
			}
		}
		else { // 오른쪽으로 이동
			for (int i = 0; i < cnt; i++) {
				next++;

				if (next > n) next = 1;

				// 이미 터진 풍선은 뺀다
				while (burst[next]) {
					next++;
					if (next > n)
						next = 1;
				}
			}
		}
		cout << next << ' ';
	}
	
	return 0;
}