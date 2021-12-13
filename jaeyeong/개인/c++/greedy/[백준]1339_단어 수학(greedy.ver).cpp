using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int alpha[26];
bool compare(int a, int b) {
	return a > b;
}
int main() {
	vector<string> input;
	int n, answer = 0;
	string s;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		input.push_back(s);
	}

	for (int i = 0; i < n; i++) {
		int pow = 1;
		for (int j = input[i].size()-1; j >= 0; j--) {
			alpha[input[i][j] - 'A'] += pow;
			pow *= 10;
		}
	}

	sort(alpha, alpha + 26, compare);

	int k = 9;
	for (int i = 0; i <26; i++) {
		if (alpha[i] == 0) break;
		answer += alpha[i] * (k - i);
	}
	cout << answer << '\n';
}