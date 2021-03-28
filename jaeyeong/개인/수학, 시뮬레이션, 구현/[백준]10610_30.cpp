#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
	return a > b;
}
int main() {
	int num[10] = {}, sum = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		num[s[i] - '0']++;
		sum += s[i] - '0';
	}

	if (sum % 3 == 0 && num[0] != 0) {
		for (int i = 9; i >= 0; i--) {
			if (num[i] != 0) {
				for (int j = 0; j < num[i]; j++)
					cout << i;
			}
		}
	}
	else {
		cout << -1;
	}

	return 0;
}