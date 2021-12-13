using namespace std;
#include <iostream>
#define MAX 10000

int input[MAX];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	int answer = 0, start = 0, end = 0;
	int sum = 0;
	while (end <= n) {
		if (sum >= m) sum -= input[start++];
		else if (sum < m) sum += input[end++];
		if (sum == m) answer++;
	}
	cout << answer << '\n';
}