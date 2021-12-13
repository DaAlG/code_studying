using namespace std;
#include <iostream>

int k, input[14], visit[50], arr[14];
void combination(int cnt) {
	if (cnt == 6) {
		for (int i = 1; i <= 6; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= k; i++) {
		if (visit[input[i]] == false && input[i]>arr[cnt]) {
			visit[input[i]] = true;
			arr[cnt+1] = input[i];
			combination(cnt + 1);
			visit[input[i]] = false;
		}
	}
}
int main() {
	cin >> k;
	while (k != 0) {
		for (int i = 1; i <= k; i++)
			cin >> input[i];
		combination(0);
		cout << '\n';
		cin >> k;
	}
}