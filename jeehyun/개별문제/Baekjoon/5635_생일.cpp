/*
 * 정렬
 * 5635 생일
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Birth {
	string name;
	int year;
	int month;
	int day;
};

bool cmp(Birth a, Birth b)
{
	if (a.year == b.year) {
		if (a.month == b.month) {
			return a.day < b.day;
		}
		return a.month < b.month;
	}
	return a.year < b.year;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<Birth> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name >> arr[i].day >> arr[i].month >> arr[i].year;
	}
	sort(arr.begin(), arr.end(), cmp);

	cout << arr.back().name << '\n';
	cout << arr.front().name << '\n';
	
	return 0;
}