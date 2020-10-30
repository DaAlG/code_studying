/*
n*m의 보드, 4개의 버튼이 있다.
칸은 비어있거나, 동전, 벽이다.
동전은 2개이다.
버튼은 왼쪽, 오른쪽, 위, 아래이고 누르면 그 방향으로 이동한다.
이동하려는 칸이 벽이면 이동하지 않는다.
이동하려는 칸이 없으면 보드 바깥으로 떨어진다.
두 동전 중 하나만 보드에 떨어뜨리기 위해 버튼을 몇 번 눌러야하는가 => 최소값
10번보다 많이 눌러야 하면 -1을 출력한다.

4개의 버튼 최대 10번 4^10=2^20=100만가지 => 모든 방법을 다 쓰는 것
빈칸과 벽은 변하지 않음 변하는 것은 동전의 위치 뿐임
보드 매번 저장하면 공간이 매우 많이 필요하게 됨
동전의 위치만 기억
*/
#include<iostream>
using namespace std;
int n, m;
string a[20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int go(int step, int x1, int y1, int x2, int y2) {
	/*
		step: 버튼을 누른 횟수
		(x1,y1): 한 동전의 위치
		(x2,y2): 다른 동전의 위치
		1. 불가능한 경우 : 10번보다 많이 누르게 되면 불가능 step==11, 두 동전 모두 떨어진 경우
		2. 정답을 찾은 경우: 두 동전 중에서 하나만 떨어진 경우
		3. 다음 경우: 오른쪽, 왼쪽, 위, 아래 버튼 누르는 경우 처리
	*/
	if (step == 11) return -1; //11번 이동했으면 불가능한 것
	bool fall1 = false, fall2 = false;
	if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m) fall1 = true;
	if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m) fall2 = true; //각각의 동전이 떨어졌는지 확인 == 범위를 벗어난 것
	if (fall1 && fall2) return -1; //두 동전 모두 떨어진 것
	if (fall1 || fall2) return step; // 하나만 떨어졌으면 return
	int ans = -1;

	for (int k = 0; k < 4; k++) { // 네 방향 모두 check
		int nx1 = x1 + dx[k];
		int ny1 = y1 + dy[k];
		int nx2 = x2 + dx[k];
		int ny2 = y2 + dy[k];//이동해야하는 것
		if (0 <= nx1 && nx1 < n && 0 <= ny1 && ny1 < m && a[nx1][ny1] == '#') {//벽이 있으면 이동하지 않는 조건
			nx1 = x1;//이동하는 칸을 현재칸과 똑같이 바꿔줌
			ny1 = y1;
		}
		if (0 <= nx2 && nx2 < n && 0 <= ny2 && ny2 < m && a[nx2][ny2] == '#') {
			nx2= x2;
			ny2 = y2;
		}
		int temp = go(step + 1, nx1, ny1, nx2, ny2);
		if (temp == -1) continue; //불가능 하면 넘어감 .
		if (ans == -1 || ans > temp) ans = temp; //최소값 찾기
	}
	return ans;
}
int main() {
	cin >> n >> m;
	int x1, y1, x2, y2;
	x1 = y1 = x2 = y2 = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'o') {
				if (x1 == -1) {//동전 1의 위치
					x1 = i;
					y1 = j;
				}
				else {//동전 2의 위치
					x2 = i;
					y2 = j;
				}
				a[i][j] = '.';//동전이 있는 칸
			}
		}
	}
	cout << go(0, x1, y1, x2, y2) << '\n';
	return 0;
}
//어떤 정보를 재귀함수로 넘길 것인가
/*보드는 너무 많으니까 동전의 위치만 변한다는 점을 이용하여 동전의 위치만 함수의 인자로 사용*/