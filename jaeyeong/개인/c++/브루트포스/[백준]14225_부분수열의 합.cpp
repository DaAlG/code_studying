using namespace std;
#include <iostream>
#include <vector>

int n;
int arr[21];
int visit[21];
bool c[20 * 100000 + 10];
vector<int> answer;

void combination(int idx, int k, int cnt) {
	if (cnt == k) {
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if(visit[i]==true)
				sum += arr[i];
		}
		c[sum] = true;
		return;
	}
	for (int i = idx; i <= n; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			combination(i, k, cnt + 1);
			visit[i] = false;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
		combination(1, i, 0);

	int k = 20 * 100000 + 10;
	for (int i = 1; i < k; i++) {
		if (c[i] != true) {
			cout << i << '\n';
			break;
		}
	}
}