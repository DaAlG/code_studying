/*
 * 누적 합
 * 20440 🎵니가 싫어 싫어 너무 싫어 싫어 오지 마 내게 찝쩍대지마🎵 - 1
 */

#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 2100000001
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, Te, Tx;
	cin >> n;

	vector<pair<int, int>> time;
	for (int i = 0; i < n; i++) {
		cin >> Te >> Tx;
		time.push_back({ Te, Tx });
	}

	vector<int> w;
	for (auto t : time) {
		w.push_back(t.first);
		w.push_back(t.second);
	}
	sort(w.begin(), w.end());
	w.erase(unique(w.begin(), w.end()), w.end());

	// 좌표 압축
	for (auto& t : time) {
		t.first = lower_bound(w.begin(), w.end(), t.first) - w.begin();
		t.second = lower_bound(w.begin(), w.end(), t.second) - w.begin();
	}

	
	vector<int> mosquito(w.size() + 1);
	for (auto t : time) {
		mosquito[t.first]++;
		mosquito[t.second]--;
	}

	// prefix sum
	for (int i = 1; i < mosquito.size(); i++) {
		mosquito[i] += mosquito[i - 1];
	}

	// 최대 모기 마릿수를 구한다
	auto res = max_element(mosquito.begin(), mosquito.end());
	int Tem = distance(mosquito.begin(), res);

	cout << *res << '\n';

	// 모기가 가장 많이 있는 시간대를 구한다
	for (int i = Tem; i <= mosquito.size(); i++) {
		if (i == mosquito.size() || mosquito[i] ^ *res) {
			// 좌표 압축 이전 값 출력 
			cout << w[Tem] << ' ' << w[i] << '\n';
			break;
		}
	}

	return 0;
}