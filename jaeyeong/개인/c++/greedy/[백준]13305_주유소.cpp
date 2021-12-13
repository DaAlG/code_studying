using namespace std;
#include <iostream>
#include <algorithm>
#define MAX 100000

int dis[MAX], price[MAX];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++)
		cin >> dis[i];
	for (int i = 0; i < n; i++)
		cin >> price[i];

	int idx, next;
	long long pay = 0;
	for (int i = 0; i < (n-1);) {
		//next가 다음 충전지
		next = i + 1;
		while (price[i] < price[next]) {
			next++;
		}
		for (int j = i + 1; j <= next; j++)
			pay += 1LL * price[i] * dis[j];
		i = next;
	}
	cout << pay << '\n';
}