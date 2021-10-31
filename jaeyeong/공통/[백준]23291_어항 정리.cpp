using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
int n;
vector<vector<int>> v;

void addFish() {
	int minValue = 0x3f3f3f3f;
	for(int i = 0; i < v.size(); i++)
		if (minValue > v[i][0]) minValue = v[i][0];
	for (int i = 0; i < v.size(); i++) {
		if (v[i][0] == minValue) v[i][0]++;
	}
}

int maxValSize2x(vector<vector<int>> tv) {
	int resSize = -1;
	for (int i = 0; i < tv.size(); i++) {
		if (tv[i].size() > resSize) resSize = tv[i].size();
	}
	return resSize;
}
vector<vector<int>> rotate() {
	vector<vector<int>> tv, rv;
	stack<int> idx;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].size() >= 2) {
			tv.push_back(v[i]);
			idx.push(i);
		}
	}
	while (idx.size()) {
		v.erase(v.begin() + idx.top());
		idx.pop();
	}
	rv.resize(tv.size());
	int maxJ = maxValSize2x(tv);
	int j = 0;
	while (j < maxJ) {
		for (int i = tv.size() - 1; 0 <= i; i--) {
			if(tv[i].size()<=j+1) rv[j].push_back(tv[i][j]);
		}
		j++;
	}
	return rv;
}
int solution() {
	//1. ������� ���� ���� ���� ���׿� ����� �ֱ�
	addFish();
	//2. ���׽ױ�
	while (1) {
		//���ʿ� �ִ� ������ �����ʿ� �ִ� ������ ���� �÷� ����
		v[1].insert(v[1].end(), v[0].begin(), v[0].end());
		v.erase(v.begin());
		//2�� �̻� �׿��ִ� ������ ��� ���ߺξ��Ų
		//���� ��ü�� 90�� ȸ��
		vector<vector<int>> rotateV = rotate();
		if (rotateV.size() > v.size()) break;
		for (int i = 0; i < rotateV.size(); i++) {
			v[i].insert(v[i].end(), rotateV[i].begin(), rotateV[i].end());
		}
	}
	//3. ���� �� ����� �� ����
	vector<vector<int>> plus;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v[i].size(); j++) {
			// �������� ����
		}
	}

	//4. ������ �ٴڿ� �Ϸķ� ����
	//5. ���ߺξ� �ι��ϱ�
	//6. ���� �� ����� �� ����
	//7. ������ �ٴڿ� �Ϸķ� ����
}
int main() {
	int k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		vector<int> nv(1);
		cin >> nv[i];
		v.push_back(nv);
	}

	int cnt = 1;
	while (1) {
		int dif = solution();
		if (dif <= k) break;
		cnt++;
	}
	cout << cnt << '\n';
}