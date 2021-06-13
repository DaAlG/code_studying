using namespace std;
#include <iostream>
#define MAX 100000

int arr[MAX]; //arr[i] = 작동 i회로 갈 수 있는 최대 거리

int main() {
	arr[1] = 1;
	int maxV = 1;
	for (int i = 2; i < MAX; i++) {
		if (i % 2 == 0) {
			arr[i] = arr[i - 1] + maxV;
			maxV++;
		}
		else arr[i] = arr[i - 1] + maxV;
	}

	int tc, a, b, dis;
	cin >> tc;
	while (tc--) {
		cin >> a >> b;
		dis = b - a;
		if (dis == 1) cout << "1\n";
		else if (dis > 2147441940) cout << "92681\n";
		else {
			for (int i = 2; i < MAX; i++) {
				if (arr[i - 1] < dis && dis <= arr[i]) {
					cout << i << '\n';
					break;
				}
			}
		}
	}
	return 0;
}
/*
* 2: 1 1           2
* 3: 1 1 1         3
* 4: 1 2 1         3
* 5: 1 2 1 1       4
* 6: 1 2 2 1       4
* 7: 1 2 2 1 1     5
* 8: 1 2 2 2 1     5
* 9: 1 2 3 2 1     5
* 10:1 2 3 2 1 1   6
* 11:1 2 3 2 2 1   6
* 
* 1 1  //2
* 1 2 1 //3
* 1 2 2 1 //4
* 1 2 3 2 1
* 1 2 3 3 2 1
*/