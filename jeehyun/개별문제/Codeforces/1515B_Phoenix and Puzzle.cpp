#include <iostream>
#include <cmath>
using namespace std;

bool isSquare(int n) {
	int tmp = (int)sqrt(n);
	return tmp * tmp == n;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int n;
		cin >> n;

		// 삼각형 2개로 만든 정사각형으로 만들 수 있는지 확인
		if (n % 2 == 0 && (n / 2 == 1 || isSquare(n / 2)))
			cout << "YES\n";
		else if (n % 4 == 0 && (n / 4 == 1 || isSquare(n / 4))) // 삼각형 4개로 만든 정사각형으로 만들 수 있는지 확인
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}