using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 200001

int home[MAX];
int main() {
	int n, c;
	cin >> n >> c;

	for (int i = 0; i < n; i++)
		cin >> home[i];
	sort(home, home+n);

	//����Ž��
	int low = 1;//�ּҰŸ�
	int high = home[n - 1] - home[0]; //�ִ�Ÿ�
	int cnt, tmp, mid, answer;
	while (low <= high) {
		cnt = 1;//�� ������ ������ �Ÿ��� �ִ�� �ϱ� ���ؼ� ù��° ���� �����Ⱑ ��ġ�Ǿ�� �Ѵ�.
		tmp = home[0];
		mid = (low + high) / 2;

		for (int i = 1; i < n; i++) {
			int d = home[i] - tmp;
			if (mid <= d) {
				cnt++;
				tmp = home[i];
			}
		}

		if (cnt >= c) { //���� ������� >=��ġ�� �������
			//������ �� ���� �ø���
			answer = mid;
			low = mid + 1;
		}
		else {
			//������ ���� ���� ���̱�
			high = mid - 1;
		}
	}
	cout << answer << '\n';
}