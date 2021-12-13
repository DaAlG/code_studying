using namespace std;

#include <iostream>
#define MAX (1<<21)
#define PIV ((1 << 20)-1)
long long tree[PIV * 2];

void update(long long n, long long v) { //n번째 리프 노드값을 v로 바꾸기.
	n += PIV;
	tree[n] = v;
	//조상 노드들 값도 업데이트 하자
	while ((n = n / 2) > 0) { //조상에 다다를 때까지
		//내 윗 조상 = 왼쪽자식 + 오른쪽자식
		tree[n] = tree[n * 2] + tree[n * 2 + 1];
	}
}

long long query(long long l, long long r) { //l ~ r까지의 구간합
	l += PIV, r += PIV;
	long long ret = 0;
	while (l <= r) {
		if (l % 2 == 1) ret += tree[l++]; //l의 경우 최초의 홀수 조상의 노드를 더하기
		if (r % 2 == 0) ret += tree[r--]; //r의 경우 최초의 짝수 조상의 노드를 더하기
		l /= 2, r /= 2;
	}
	return ret;
}
int main() {
	int n, m, k;
	long long a, b, c;

	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		update((long long)i, a);
	}
	for (int i = 0; i < m + k; i++) {

		cin >> a >> b >> c;
		if (a == 1) update(b, c);
		else cout << query(b, c) << '\n';
	}

}