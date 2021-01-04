// SW Expert Academy
// S/W 문제해결 기본 2일차 - 1209 Sum

#include <iostream>
#include <cstring>

using namespace std;

int main() {
	int test_case;
	int T = 10;
	const int size = 100;
	int arr[size+1][size+1];
	int diag, ans, num;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> test_case;
		
		for (int i = 0; i <= size; i++) {
			memset(arr[i], 0, sizeof(int) * (size + 1));
		}
		diag = ans = 0;

		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				cin >> arr[i][j];

				arr[i][size] += arr[i][j];
				arr[size][j] += arr[i][j];

				if (i == j)
					arr[size][size] += arr[i][j];

				if (i + j == size - 1)
					diag += arr[i][j];

				if ((num = max(max(arr[i][size], arr[size][j]), max(arr[size][size], diag))) > ans)
					ans = num;
			}
		}


		cout << "#" << test_case << " " << ans << endl;
	}

	return 0;
}