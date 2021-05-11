/*
 * 투 포인터
 * 19644 좀비 떼가 기관총 진지에도 오다니
 */

#include <iostream>
#include <queue>
#define MAX 3000001
using namespace std;

int map[MAX];
bool bomber[MAX];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L, mL, mK, C, tmp;
	cin >> L >> mL >> mK >> C;

	for (int i = 0; i < L; i++) {
		cin >> map[i];
	}

	int start = -mL + 1;
	int end = 0;
	int bomb = mL - 1;
	int totalDamage = mL * mK;

	while (end < L) {
		int damage = totalDamage - bomb * mK;
		if (damage < map[end]) {
			if (--C < 0) {
				cout << "NO";
				return 0;
			}
			bomb++;
			bomber[end] = true;
		}

		if (start < 0 || bomber[start])
			bomb--;

		start++;
		end++;
	}
	cout << "YES";

	return 0;
}