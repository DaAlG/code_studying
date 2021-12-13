using namespace std;
#include <iostream>

int arr[22], n;


void solution(int x) {
	arr[x] = arr[x - 1] + arr[x - 2];
	if (x == n) return;
	solution(x + 1);
}

int main() {
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	if(n>1)
		solution(2);
	cout << arr[n] << '\n';
}