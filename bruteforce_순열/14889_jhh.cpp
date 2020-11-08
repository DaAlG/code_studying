#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<vector<int>>a(n, vector<int>(n)); /*능력치 배열*/
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin >> a[i][j];
	
	/* 순열 이용할 배열*/
	vector<int> b(n) 
	
	/*0이 n/2개 1이 n/2개*/
	for (int i = 0; i < n / 2; i++)
		b[i] = 1;

	sort(b.begin(), b.end());
	int ans = 2147483647;

	do {
		vector<int> first, second; /*first와 second는 n/2*/
		for (int i = 0; i < n; i++) {
			if (b[i] == 0)
				first.push_back(i);
			else second.push_back(i);
		}
		int one = 0;
		int two = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = 0; j < n / 2; j++) {
				if (i == j) continue; /*자기 자신과 매칭 될 때*/
				one += a[first[i]][first[j]];
				two += a[second[i]][second[j]];
			}
		}
		/*두 팀 능력치의 차이 이용하여 최소 구함*/
		int diff = one - two; 
		if (diff < 0) diff = -diff;
		if (ans > diff) ans = diff;
	} while (next_permutation(b.begin(), b.end()));
	cout << ans << '\n';

	return 0;
}
