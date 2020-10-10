/*
�����ڸ� �ϳ��� �����־ ���� �� �ִ� ���� ����� �ִ밪�� �ּҰ��� ���ϴ� ����
������ ����� ������ �켱������ �����ϰ� �տ������� �����Ѵ�.
���� ������ �ٲ� �� ����.
��� ����� ����� ����� �� ���
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> calc(vector<int>& a, int index, int cur, int plus, int minus, int mul, int div) {//�� ���� ���� return �ؾ���: �ּ�&�ִ밪
	/*
	a: �Է����� �־��� ����
	index: ���� ����ؾ��ϴ� �ε���
	cur: index-1��°���� ����� ���
	plus,minus,mul,div: ����� �� �ִ� �������� ����
	*/
	int n = a.size();
	if (index == n) return make_pair(cur, cur);
	vector<pair<int, int>>res; 
	if (plus > 0) res.push_back(calc(a, index + 1, cur + a[index], plus - 1, minus, mul, div)); //plus �Ѱ� ���
	if (minus > 0) res.push_back(calc(a, index + 1, cur - a[index], plus, minus-1, mul, div));
	if (mul > 0) res.push_back(calc(a, index + 1, cur * a[index], plus , minus, mul-1, div));
	if (div > 0) res.push_back(calc(a, index + 1, cur / a[index], plus, minus, mul, div-1));
	auto ans = res[0];
	for (auto p : res) {
		if (ans.first < p.first)
			ans.first = p.first;
		if (ans.second > p.second)
			ans.second = p.second;
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int plus, minus, mul, div;
	cin >> plus >> minus >> mul >> div;
	auto p = calc(a, 1, a[0], plus, minus, mul, div); //0��° index �տ��� ������ ���� �� ���� a[1]���� ����ϴ� �� ����
	cout << p.first << '\n';
	cout << p.second << '\n';
	return 0;
}