using namespace std;
#include <iostream>

int n;
int arr[1001], res[1001];


int main() {
	int x, needA, needB;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		arr[i] = x;
	}
	if (n == 1) {
		cout << arr[n] << '\n';
		return 0;
	}
	else {
		res[1] = arr[1];
		if (arr[2] > (res[1] * 2)) res[2] = arr[2];
		else res[2] = res[1] * 2;
		for (int i = 3; i <= n; i++) {
			int max_value = -1;
			for (int j = 0; j <= i/2; j++) {
				int a = j;
				int b = i - j;
				needA = res[a];
				if (res[b] != 0)
					needB = res[b];
				else
					needB = arr[b];
				if ((needA + needB) > max_value)
					max_value = needA + needB;
			}
			res[i] = max_value;
		}

		cout << res[n] << '\n';
		return 0;
	}
}