using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int n;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int done = false, x;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	if (prev_permutation(arr.begin(), arr.end())) {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}
	else
		cout << "-1\n";
}