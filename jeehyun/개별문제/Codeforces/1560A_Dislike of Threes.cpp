#include <iostream>

using namespace std;

int main()
{
	int T, k;
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> k;

		int cnt = 0;
		int num = 0;

		do {
			num++;
			if (num % 3 != 0 && num % 10 != 3) {
				cnt++;
			}
		} while (cnt < k);
		cout << num << "\n";
	}
	
	return 0;
}