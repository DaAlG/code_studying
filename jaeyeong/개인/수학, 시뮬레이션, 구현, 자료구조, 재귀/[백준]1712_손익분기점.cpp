using namespace std;
#include <iostream>

int main() {
	int a; //�������
	int b; //�������
	int c; //���� ����
	cin >> a >> b >> c;
	if (b >= c) {
		cout << "-1\n";
		return 0;
	}
	int res = a / (c - b); // res���� ū n �ʿ�
	cout << res+1 << '\n';
	return 0;
}