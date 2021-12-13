using namespace std;
#include <iostream>
#include <vector>

int students[101]; //학생별 추천받은 횟수
vector<pair<int, int>> v; //(추천받은 학생 번호, 언제 게시되었는지)
bool ans[101]; //정답 정렬용 배열

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
		if (inRange(x)) { //x는 이미 사진 틀에 있는 사진
			students[x]++;
		}
		else if (v.size() >= n) {
			//사진틀에 없고, 사진틀이 꽉 찬 경우
			delStudent();
			students[x]++;
			v.push_back(make_pair(x, i));
		}
		else {
			//사진틀에 없고, 사진틀이 덜 찬 경우
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