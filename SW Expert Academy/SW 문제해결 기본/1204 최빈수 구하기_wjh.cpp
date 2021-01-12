// SW Expert Academy
// S/W 문제해결 기본 1일차 - 1204 최빈수 구하기

#include <iostream>

using namespace std;

const int TOTAL = 1000;
int T;

int main() {

	cin >> T;

	while(T--) {
		int testNum;
		cin >> testNum;
		cout << "#" << testNum << " ";

		int index, mode;
		int arr[101] = { 0, };
		int max = 0;
		for (int i = 0; i < TOTAL; i++) {
			cin >> index;
			arr[index]++;

			if (arr[index] > max)
				max = arr[index];
		}

		for (int i = 0; i < 101; i++) {
			if (arr[i] == max)
				mode = i;
		}

		cout << mode << endl;
	}

	return 0;
}