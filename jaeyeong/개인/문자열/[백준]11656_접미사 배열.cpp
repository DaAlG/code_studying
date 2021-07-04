using namespace std;
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

int main() {
	string s;
	cin >> s;
	int size = s.size();
	vector<string> ans(size);
	for (int i = 1; i <= s.size(); i++) {
		ans[i-1] = s.substr(size - i, i);
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < size; i++)
		cout << ans[i] << '\n';
	return 0;
}