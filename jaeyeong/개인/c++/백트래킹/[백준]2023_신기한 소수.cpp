using namespace std;
#include <iostream>
#define MAX 1001

int n;
int arr[8];
int a[1001];

bool prime(int num) {
	if (num == 0 || num == 1)
		return false;
	for (int i = 2; i * i <= num; i++)
		if (num % i == 0)
			return false;
	return true;
}
void cal(int num, int len) {
	if (len == n) {
		cout << num << '\n';
	}
	//È¦¼ö¸¸
	for (int i = 1; i <= 9; i += 2) {
		if (prime(num * 10 + i))
			cal(num * 10 + i, len + 1);
	}
}

int main() {
	cin >> n;
	cal(2, 1);
	cal(3, 1);
	cal(5, 1);
	cal(7, 1);
}