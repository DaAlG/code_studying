#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		int k;
		string s;
		cin >> k >> s;

		vector<string> arr;
		for (int i = 0; i < s.size(); i++) {
			for (int j = i; j < s.size(); j++) {
				arr.push_back(s.substr(i, j - i + 1));
			}
		}
		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		cout << "#" << test_case << " ";
		
		if (arr.size() < k) cout << "none\n";
		else cout << arr[k - 1] << "\n";
	}
	return 0;
}