#include <iostream>

using namespace std;

int n, m;
int set[1000001];

int getParent(int x)
{
	if (x == set[x]) return x;
	return set[x] = getParent(set[x]);
}

void unionParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	if (a < b) set[b] = a;
	else set[a] = b;
}

int findParent(int a, int b)
{
	a = getParent(a);
	b = getParent(b);
	return a == b;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i <= n; i++) set[i] = i;
	
	for (int i = 0; i < m; i++) {
		int cmd, a, b;
		cin >> cmd >> a >> b;

		if (cmd == 0) {
			if (!findParent(a, b)) unionParent(a, b);
		}
		else {
			if (findParent(a, b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}