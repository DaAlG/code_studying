using namespace std;
#include <iostream>
#include <vector>

int main() {
	vector<string> v[201];
	int n, maxAge=1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int k;
		cin >> k >> s;
		v[k].push_back(s);
		maxAge = max(k, maxAge);
	}
	for (int i = 1; i <= maxAge; i++)
		for(int j=0;j<v[i].size();j++)
			cout << i << ' ' << v[i][j] << '\n';
		
	return 0;
}