using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;

	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		arr[i] = i + 1;

	do {
		for (int i = 0; i < n; i++)
			cout << arr[i] << ' ';
		cout << '\n';
	}while(next_permutation(arr.begin(), arr.end()) );

}