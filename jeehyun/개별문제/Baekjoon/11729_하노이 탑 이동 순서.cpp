/* 분할정복
 * 11729 하노이 탑 이동 순서
 */

#include <iostream>
#include <vector>
using namespace std;

int ans = 0;
vector<pair<int, int>> record;

// a : 처음, b : 거쳐가는 장대, c : 도착
void hanoi(int a, int b, int c, int n)
{
	if (n <= 0)
		return;

	ans++;
	hanoi(a, c, b, n - 1);
	record.push_back({ a, c });
	hanoi(b, a, c, n - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	hanoi(1, 2, 3, n);

	cout << ans << "\n";
	for (int i = 0; i < record.size(); i++)
		cout << record[i].first << " " << record[i].second << "\n";

	return 0;
}