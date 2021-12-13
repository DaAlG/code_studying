using namespace std;
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> v(n), answer;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	string s;
	for (int i = 0; i < m; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s))
			answer.push_back(s);
	}
	sort(answer.begin(), answer.end());
	int size = answer.size();
	cout << size << '\n';
	for (int i = 0; i < size; i++)
		cout << answer[i] << '\n';
	return 0;
}