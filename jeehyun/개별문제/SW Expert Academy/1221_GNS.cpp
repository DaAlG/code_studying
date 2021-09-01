#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int n;
int cnt[10];
map<string, int> num;
string key[] = { "ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN" };

void init() 
{
	for (int i = 0; i < 10; i++) {
		num[key[i]] = i;
	}
}

int main()
{
	int T;
	cin >> T;
	init();

	for (int test_case = 1; test_case <= T; test_case++) {
		string s;
		cin >> s >> n;
		fill_n(cnt, 10, 0);

		string word;
		for (int i = 0; i < n; i++) {
			cin >> word;
			cnt[num[word]]++;
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < cnt[i]; j++)
				cout << key[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}