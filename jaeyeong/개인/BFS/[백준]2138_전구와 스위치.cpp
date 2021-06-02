using namespace std;
#include <iostream>
#define MAX 100000

int n;
int arr1[MAX], arr2[MAX], brr[MAX];

bool isSame(int arr[]) {
	for (int i = 0; i < n; i++)
		if (arr[i] != brr[i]) return false;
	return true;
}

void turn(int arr[],int idx) {
	for (int i = idx - 1; i <= idx + 1; i++)
		if(0<=i && i<n) arr[i] = 1 - arr[i];
}

int solve(int arr[], int start) {
	int answer=start;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] != brr[i - 1]) {
			turn(arr,i);
			answer++;
		}
	}
	if (!isSame(arr))answer = -1;
	return answer;
}

int main() {

	cin >> n;
	char x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr1[i] = x - '0';
		arr2[i] = x - '0';
	}
	for (int i = 0; i < n; i++) {
		cin >> x;
		brr[i] = x - '0';
	}

	int a1 = solve(arr1,0);
	turn(arr2,0);
	int a2 = solve(arr2,1);

	if (a1 == -1 && a2 == -1) cout << "-1\n";
	else if (a1 != -1 && a2 == -1) cout << a1 << '\n';
	else if (a1 == -1 && a2 != -1) cout << a2 << '\n';
	else cout << min(a1, a2) << '\n';
	return 0;
}