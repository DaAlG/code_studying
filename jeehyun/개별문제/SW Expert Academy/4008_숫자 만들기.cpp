#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000000
using namespace std;

int n;
int ops[4];
int num[12];

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		cin >> n;
		for (int i = 0; i < 4; i++) cin >> ops[i];
		for (int i = 0; i < n; i++) cin >> num[i];

		vector<int> op;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < ops[i]; j++) {
				op.push_back(i);
			}
		}

		int maxi = -MAX;
		int mini = MAX;
		do {
			int result = num[0];
			int idx = 1;

			for (int i = 0; i < op.size(); i++) {
				if (op[i] == 0) result += num[idx++];
				else if (op[i] == 1) result -= num[idx++];
				else if (op[i] == 2) result *= num[idx++];
				else result = result / num[idx++];
			}

			maxi = max(maxi, result);
			mini = min(mini, result);

		} while (next_permutation(op.begin(), op.end()));

		cout << "#" << test_case << " " << maxi - mini << "\n";
	}
	return 0;
}