using namespace std;
#include <iostream>
#include <vector>

int students[101]; //�л��� ��õ���� Ƚ��
vector<pair<int, int>> v; //(��õ���� �л� ��ȣ, ���� �ԽõǾ�����)
bool ans[101]; //���� ���Ŀ� �迭

void delStudent() {
	int min_idx = 0;
	int min_student = 0, min_recNum = 0x3f3f3f3f;
	for (int i = 0; i < v.size(); i++) {
		if (min_recNum > students[v[i].first]) {
			min_idx = i;
			min_recNum = students[v[i].first];
		}
		else if (min_recNum == students[v[i].first]) {
			if (v[i].second < v[min_idx].second)
				min_idx = i;
		}
	}
	students[v[min_idx].first] = 0;
	v.erase(v.begin() + min_idx);
	
	return;
}
bool inRange(int x){
	for (int i = 0; i < v.size(); i++)
		if (v[i].first == x) return true;
	return false;
}
int main() {
	int n, num_cc;
	int x;
	cin >> n >> num_cc;
	for (int i = 0; i < num_cc; i++) {
		cin >> x;
		if (inRange(x)) { //x�� �̹� ���� Ʋ�� �ִ� ����
			students[x]++;
		}
		else if (v.size() >= n) {
			//����Ʋ�� ����, ����Ʋ�� �� �� ���
			delStudent();
			students[x]++;
			v.push_back(make_pair(x, i));
		}
		else {
			//����Ʋ�� ����, ����Ʋ�� �� �� ���
			students[x]++;
			v.push_back(make_pair(x, i));
		}
	}
	for (int i = 0; i < v.size(); i++)
		ans[v[i].first] = true;
	for (int i = 1; i <= 100; i++)
		if (ans[i]) cout << i << ' ';
	cout << '\n';
}