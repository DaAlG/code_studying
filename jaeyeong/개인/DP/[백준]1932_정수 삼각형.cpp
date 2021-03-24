using namespace std;
#include <iostream>
#include <vector>

int n;
int triangle[125251];

int main() {
	int k = 1, x, node=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		node += i;
	for (int i = 1; i <= node; i++) {
		cin >> triangle[i];
	}

	while (n) {
		int start = 1;
		for (int i = 1; i < n; i++)
			start += i;
		for (int i = start; i < (start+n-1); i++) {
			triangle[i - (n - 1)] += max(triangle[i], triangle[i + 1]);
		}
		n--;
	}

	cout << triangle[1] << '\n';
}