#include <iostream>
#include <vector>
#define MAX 1000001
using namespace std;

int n;
int minFactor[MAX];
vector<int> prime;

void eratosthenes() 
{
	minFactor[0] = minFactor[1] = -1;
	for (int i = 2; i < MAX; i++) {
		minFactor[i] = i;
	}

	for (int i = 2; i * i < MAX; i++) {
		if (minFactor[i] == i) {
			for (int j = i * i; j < MAX; j += i) {
				if (minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}

	for (int i = 2; i < MAX; i++) {
		if (minFactor[i] == i)
			prime.push_back(i);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	eratosthenes();

	vector<int> used(prime.size()); // 소수가 사용된 횟수
	vector<vector<int>> factor(n, vector<int>(prime.size())); // 소인수분해 했을 때 소수의 개수

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;

		for (int j = 0; j < prime.size(); j++) {
			// 소인수 분해
			while (!(k % prime[j])) {
				factor[i][j]++;
				used[j]++;
				k /= prime[j];
				if (k == 1) break;
			}
			if (k == 1) break;
		}
	}

	int answer = 1;
	int cnt = 0;

	for (int i = 0; i < prime.size(); i++) {
		// 최대공약수의 일부가 될 수 있는지 판단
		int tmp = used[i] / n;
		for (int j = 0; j < tmp; j++)
			answer *= prime[i];

		for (int j = 0; j < n; j++) {
			if (tmp > factor[j][i])
				cnt += tmp - factor[j][i];
		}
	}
	cout << answer << " " << cnt << "\n";
	return 0;
}