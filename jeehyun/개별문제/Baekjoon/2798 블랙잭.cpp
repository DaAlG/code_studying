/* Brute Force
 * 카드의 합이 21을 넘지 않는 한도 내에서, 카드의 합을 최대로.
 * 각 카드에는 양의 정수가 쓰여있으며
 * 딜러는 N장의 카드를 숫자가 보이도록 바닥에 놓는다.
 * 딜러는 숫자 M을 크게 외침
 * 플레이어는 제한된 시간 안에 N장의 카드 중에서 3장의 카드 골라야함
 * 카드의 합은 M을 넘지 않으면서 M과 최대한 가깝게.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;

	vector<int> card(N);
	for (int i = 0; i < N; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());
	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				int sum = card[i] + card[j] + card[k];

				if (sum > M)
					continue;

				if (sum > ans)
					ans = sum;
			}
		}
	}

	cout << ans << endl;
}