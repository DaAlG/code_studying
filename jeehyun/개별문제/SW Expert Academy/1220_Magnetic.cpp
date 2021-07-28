#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int T = 1;
	for (int test_case = 1; test_case <= T; test_case++) {
		int n, pole;
		cin >> n;

		vector<int> status(n);
		int answer = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> pole;
				if (pole == 2 && status[j] == 1) {
					answer++;
					status[j] = 0;
				}
				else if (pole == 1)
					status[j] = 1;
			}
		}
		cout << "#" << test_case << " " << answer << "\n";
	}

	return 0;
}