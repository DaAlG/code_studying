using namespace std;
#include <iostream>
#define MAX 20000

int fence[MAX];
int solve(int left, int right) {
	//���ڰ� �ϳ��ۿ� ���� ���
	if (left == right) return fence[left];

	//[left,mid],[mid+1,right]�� �� �������� ������ �����Ѵ�.
	int mid = (left + right) / 2;
	//������ ������ ���� ���� (�κ� ���� 1,2)
	int ret = max(solve(left, mid), solve(mid + 1, right));
	//�κй���3: �� �κп� ��� ��ġ�� �簢�� �� ���� ū ���� ã�´�.
	int lo = mid, hi = mid + 1;
	int height = min(fence[lo], fence[hi]);
	//[mid, mid+1]�� �����ϴ� �ʺ� 2�� �簢���� ����Ѵ�.
	ret = max(ret, height * 2);
	//�簢���� �Է� ��ü�� ���� ������ Ȯ���� ������.
	while (left < lo || hi < right) {
		//�׻� ���̰� �� ���� ������ Ȯ���Ѵ�.
		if (hi < right && (lo == left || fence[lo - 1] < fence[hi + 1])) {
			hi++;
			height = min(height, fence[hi]);
		}
		else {
			lo--;
			height = min(height, fence[lo]);
		}
		//Ȯ���� �� �簢���� ����
		ret = max(ret, height * (hi - lo + 1));
	}
	return ret;
}
int main() {
	int tc, n;
	cin >> tc;
	while (tc--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> fence[i];
		int ans = solve(0,n-1);
		cout << ans << '\n';
	}
}