using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n, m, k;
	cin >> n >> m >> k; //그룹의 개수 m, 각 그룹의 크기<=k
	vector<int> a(n); //정답

	if (m + k - 1 <= n && n <= m * k) {
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		vector<int> g; //그룹 경계의 위치
		g.push_back(0);
		g.push_back(k);//먼저 크기 k지정해서 0~k 넣기
		n -= k;
		m -= 1;
		int gs = m == 0 ? 1 : n / m; //그룹의 크기
		int r = m == 0 ? 0 : n % m; //나머지 그룹이 있는가
		for (int i = 0; i < m; i++) {
			g.push_back(g.back() + gs + (r > 0 ? 1 : 0));
			if (r > 0) r -= 1;
			//m개의 그룹 중 r개는 n/m+1의 크기, m-r개의 그룹은 n/m의 크기를 가짐
		}
		for (int i = 0; i < g.size() - 1; i++)
			reverse(a.begin() + g[i], a.begin() + g[i + 1]);
		for (int i = 0; i < a.size(); i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
	else cout << "-1\n";
	return 0;
}