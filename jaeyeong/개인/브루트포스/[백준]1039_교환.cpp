using namespace std;
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#define MAX 1000001

int n, k;
bool visit[MAX];

int conv(string buf, int l, int r) {
	//l�� r�� üũ�� �ȵǾ� ����
	//ó���� num�� �ڸ����� �������ֱ� ������ �װ� �̿��ϸ� ��
	//arr
	//char buf[16];
	//sprintf(buf, "%d", num); //���ڸ� ���ڿ��� ����ϴ� ���
	swap(buf[l], buf[r]);
	//���ڸ��� 0�� �ƴ��� üũ
	return stoi(buf);
}
int main() {
	cin >> n >> k;
	//���ܰ� �Ǵ� �͵��� �ٷ� ó��
	// 1000000 ==> �״�� ��
	// 1~9 ==> ��ȯ�� �ȵ� ==> -1
	// 10, 20, .., 90 ==> ��ȯ�� �ȵ� ==> -1
	if (1 <= n && n <= 9) {
		cout << "-1\n";
		return 0;
	}
	else if (n == 10 || n == 20 || n == 30 || n == 40 || n == 50 || n == 60 ||
		n == 70 || n == 80 || n == 90) {
		cout << "-1\n";
		return 0;
	}
	//todo - ���Ʈ����
	//���ڸ� ���� ��ȯ�ϴ� ����
	//��ȯ�ؼ� �ܰ躰�� Ž���ذ��� ����
	//�׸��� �� ���ϸ� ��
	queue<int> q;
	q.push(n);

	for (int i = 0; i < k; i++) {
		//��ȯ�ϰ� Ž�� ==> queue
		int sz = q.size();
		memset(visit, false, sizeof(visit));
		for (int j = 0; j < sz; j++) {
			int num = q.front();
			string num_s = to_string(num);
			q.pop();
			//��ȯ ����
			for (int a = 0; a < num_s.size(); a++) {
				for (int b = a + 1; b < num_s.size(); b++) {
					//��ȯ ����� queue�� �ֱ�
					//q�� �ߺ��ؼ� ���� �� �� �ֱ� ������ �ߺ�üũ
					//�ߺ�üũ ��� 1. visit �迭�� �̿�
					//�ߺ�üũ ��� 2. map�� �̿�
					if (a == 0 && num_s[b] == '0') continue;
					int x = conv(num_s, a, b);
					if (visit[x] == 0) {
						visit[x] = true;
						q.push(x);
					}
				}
			}

		}
	}
	//k���� ���ȱ� ������ q�� ���� �ִ� �͵��� k���� �����ϰ� ���� ���޸��̰�
	//q�� ���� �͵� �� ���� ū ���� ���̴�.
	int answer = q.front();
	int sz = q.size();
	while (sz--) {
		answer = max(answer, q.front());
		q.pop();
	}
	cout << answer << '\n';
	return 0;
}