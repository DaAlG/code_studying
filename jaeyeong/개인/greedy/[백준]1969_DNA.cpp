#include <iostream>
#include <string>

using namespace std;

int main() {
	int n, m, max = 0, maxInput = 0;
	string input[1001], result;
	int count[4] = { 0, }, hd = 0;
	//0:A, 1:C, 2:G, 3:T

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (input[j][i] == 'A') {
				count[0]++;
			}else if (input[j][i] == 'C') {
				count[1]++;
			}else if (input[j][i] == 'G') {
				count[2]++;
			}else if(input[j][i] == 'T'){
				count[3]++;
			}
		}
		for (int j = 0; j < 4; j++) {
			if (count[max] < count[j]) max = j;
		}

		//j��°�� ���� ���� ������ ��Ŭ����Ƽ�带 result�� append�ϱ�
		switch (max) {
		case 0:
			result += 'A';
			break;
		case 1:
			result += 'C';
			break;
		case 2:
			result += 'G';
			break;
		case 3:
			result += 'T';
			break;
		}

		hd += n - count[max];

		//ī��Ʈ �ʱ�ȭ
		for (int j = 0; j < 4; j++) {
			count[j] = 0;
		}
		max = 0;
	}

	cout << result << '\n' << hd << '\n';
}