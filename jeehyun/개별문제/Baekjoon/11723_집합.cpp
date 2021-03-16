/* 브루트포스
 * 11723 집합
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	
	int x;
	string cmd;
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		cin >> cmd;

		if (cmd == "add") {
			cin >> x;
			if (find(arr.begin(), arr.end(), x) == arr.end())
				arr.push_back(x);
		}
		else if (cmd == "remove") {
			cin >> x;
			auto it = find(arr.begin(), arr.end(), x);
			if (it != arr.end())
				arr.erase(it);
		}
		else if (cmd == "check") {
			cin >> x;
			if (find(arr.begin(), arr.end(), x) != arr.end())
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (cmd == "toggle") {
			cin >> x;
			auto it = find(arr.begin(), arr.end(), x);
			if (it != arr.end())
				arr.erase(it);
			else
				arr.push_back(x);
		}
		else if (cmd == "all") {
			arr.clear();
			for (int i = 1; i <= 20; i++)
				arr.push_back(i);
		}
		else { // empty
			arr.clear();
		}
	}

	return 0;
}