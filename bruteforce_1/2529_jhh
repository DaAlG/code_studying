#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
bool check(vector<int>& perm, vector<char>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (a[i] == '<' && perm[i] > perm[i + 1])
			return false;
		if (a[i] == '>' && perm[i] < perm[i + 1])
			return false;
	}
	return true;
}

int main() {
	int k;
	cin >> k; 
	vector<char> a(k); /*문제에 나와 있는 부등호들을 a에 넣음*/
	for (int i = 0; i < k; i++)
		cin >> a[i];

	vector<int> small(k + 1);/*가장 작은 수를 찾기 위한 배열*/
	vector<int> big(k + 1); /*가장 큰 수를 찾기 위한 배열*/

	for (int i = 0; i <= k; i++) {
		small[i] = i; /*0 부터 k까지의 수*/
		big[i] = 9 - i; /*9부터 (9-k)까지*/
	}
/*가장 작은 수 찾기*/
	do{
		if(check(small,a) break;
	}while(prev_permutation(big.begin(),big.end()));
/*가장 큰 수 찾기*/
	do {
		if (check(big, a))
			break;/*하나라도 찾으면 탐색을 하지 않고 exit*/
	} while (prev_permutation(big.begin(), big.end()));

	for (int i = 0; i < big.size(); i++)
		cout << big[i];

	cout << '\n';
	for (int i = 0; i < small.size(); i++) {
		cout << small[i];
	}
	cout << '\n';
	
	return 0;
}
