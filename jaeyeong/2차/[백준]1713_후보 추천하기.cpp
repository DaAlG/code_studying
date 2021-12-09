using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n, k; //����Ʋ�� ����, �� ��õ Ƚ��
int students[101] = { 0 };
vector<pair<int, int>> v; // ����Ʋ(�л� ��ȣ, �Խõ� ����)

bool isOnFrame(int x) {
	for (int i = 0; i < v.size(); i++)
		if (v[i].first == x) return true;
	return false;
}

void delStudent() {
	int min_recommend = 0x3f3f3f3f;
	int min_idx = 0;
	for (int i = 0; i < v.size(); i++) {
		if (min_recommend > students[v[i].first]) {
			min_idx = i;
			min_recommend = students[v[i].first];
		}
		else if (min_recommend == students[v[i].first]) {
			if (v[i].second < v[min_idx].second) {
				min_idx = v[i].first;
			}
		}
	}
	students[v[min_idx].first] = 0;
	v.erase(v.begin() + min_idx);
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		students[x]++;
		//����Ʋ�� �ִ� �л��� ���
		if (isOnFrame(x)) continue;

		//����Ʋ�� ���� ����Ʋ�� �� á�� ���
		if (v.size() >= n) {
			delStudent();
			v.push_back(make_pair(x, i));
		}
		//����Ʋ�� ���� ����Ʋ�� ������ ���� ���
		else {
			v.push_back(make_pair(x, i));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';
	cout << '\n';
}