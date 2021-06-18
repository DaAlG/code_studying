using namespace std;
#include <iostream>
#define MAX 100000

int arr[MAX];

int main() {
	int n, s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int start = 0, end = 0, answer = 0x3f3f3f3f;
	int sum = 0;
	while (end <= n) {
		if (sum >= s) {
			answer = min(answer, end-start);
			sum -= arr[start++];
		}
		else if (sum < s) sum += arr[end++];
	}
	if (answer == 0x3f3f3f3f) answer = 0;
	cout << answer << '\n';
}