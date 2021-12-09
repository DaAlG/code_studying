using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int n, k; //사진틀의 개수, 총 추천 횟수
int students[101] = { 0 };
vector<pair<int, int>> v; // 사진틀(학생 번호, 게시된 순서)

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
		//사진틀에 있는 학생일 경우
		if (isOnFrame(x)) continue;

		//사진틀에 없고 사진틀이 꽉 찼을 경우
		if (v.size() >= n) {
			delStudent();
			v.push_back(make_pair(x, i));
		}
		//사진틀에 없고 사진틀이 여유가 있을 경우
		else {
			v.push_back(make_pair(x, i));
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ';
	cout << '\n';
}