#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int calc(vector<int>&, vector<int>& b){
	int n=a.size();
	int ans=a[0]; /*맨 첫번째에는 연산자가 없음*/
	for(int i=1;i<n;i++){
	/*연산자 각각 계산*/
		if(b[i-1]==0) ans=ans+a[i];
		else if(b[i-1]==1) ans=ans=a[i];
		else if(b[i-1]==2) ans=ans*a[i];
		else ans=ans/a[i];
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> b; /*연산자 각각의 개수 만큼 넣음*/
	for (int i = 0; i < 4; i++) {
		int cnt;
		cin >> cnt;
		for (int k = 0; k < cnt; k++)
			b.push_back(i);
	}
	sort(b.begin(), b.end());
	vector<int> result;
	/*전체 순열*/
	do {
		int temp = calc(a, b);
		result.push_back(temp);
	} while (next_permutation(b.begin(), b.end()));
	auto ans = minmax_element(result.begin(), result.end());
	/*최대 & 최소 출력*/
	cout << *ans.second << '\n';
	cout << *ans.first << '\n';

	return 0;
}
