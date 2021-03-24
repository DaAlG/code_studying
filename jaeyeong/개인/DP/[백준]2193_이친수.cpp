using namespace std;
#include <iostream>

int main() {
	int n;
	long long arr[91];
	cin >> n;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
	}
	cout<<arr[n]<<'\n';
}