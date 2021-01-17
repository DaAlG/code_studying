// SW Expert Academy
// SW 문제해결 응용 1일차 - 1240 단순 2진 암호코드

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int valid(vector<int> code, int codeNum[])
{
	vector<int> num;
	int sum = 0;
	for (int i = 6, n = 1; i < code.size(); i += 7, n++) {
		int a = 0;
		for (int j = i, k = 0; k < 7; k++, j--) {
			if (code[j])
				a += (1 << k);
		}
		a = codeNum[a];
		num.push_back(a);

		if (n % 2)
			sum += a * 3;
		else
			sum += a;
	}

	if (sum % 10 == 0) {
		sum = 0;
		for (int i = 0; i < num.size(); i++)
			sum += num[i];
	}
	else
		sum = 0;

	return sum;
}

int main()
{
	int test_case;
	int T;
	cin >> T;
	
	int codeNum[128];
	codeNum[0b0001101] = 0;
	codeNum[0b0011001] = 1;
	codeNum[0b0010011] = 2;
	codeNum[0b0111101] = 3;
	codeNum[0b0100011] = 4;
	codeNum[0b0110001] = 5;
	codeNum[0b0101111] = 6;
	codeNum[0b0111011] = 7;
	codeNum[0b0110111] = 8;
	codeNum[0b0001011] = 9;
	
	for (test_case = 1; test_case <= T; ++test_case) {
		int N, M;
		cin >> N >> M;

		vector<int> code;
		int num, check = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%1d", &num);

				if (num && check) {
					check = 0;
					for (int k = 0; k < 56; k++) {
						code.push_back(num);
						scanf("%1d", &num);
					}
					j += 56;
				}
			}
		}

		while (code.back() == 0) {
			code.insert(code.begin(), 0);
			code.pop_back();
		}

		cout << "#" << test_case << " " << valid(code, codeNum) << endl;
	}

	return 0;
}