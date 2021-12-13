using namespace std;
#include <iostream>
#define MAX 1000001

int n, m;
int p[MAX];

int getParent(int x) {
	if (p[x] == x) return x;
	return p[x] = getParent(p[x]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) p[b] = a;
	else p[a] = b;
}

bool sameParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a == b) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		p[i] = i;
	int s, a, b;
	while (m--) {
		cin >> s >> a >> b;
		if (s == 0) { //a, b를 합집합
			unionParent(a, b);
		}
		else { // a, b가 같은 집합에 포함되어 있는가
			if (sameParent(a, b) == true)
				cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}