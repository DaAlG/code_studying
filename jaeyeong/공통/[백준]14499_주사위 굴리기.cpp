using namespace std;
#include <iostream>

int east = 1, west = 2, north = 3, south = 4, bottom=5, top=0;

void moveEast(int *dice) {
	int temp = dice[bottom]; //bottom
	dice[bottom] = dice[east];	//east→bottoom
	dice[east] = dice[top];	//top → east
	dice[top] = dice[west];	//west → north
	dice[west] = temp;		//bottom → west
	return;
}
void moveWest(int* dice) {
	int temp = dice[west]; //west
	dice[west] = dice[top];	//top→west
	dice[top] = dice[east];	//east → top
	dice[east] = dice[bottom];	//bottom → east
	dice[bottom] = temp;	//west → bottom
	return;
}
void moveNorth(int* dice) {
	int temp = dice[north]; //north
	dice[north] = dice[top];//top→north
	dice[top] = dice[south];//south→top
	dice[south] = dice[bottom];//bottom → south
	dice[bottom] = temp; //north → bottom
	return;
}
void moveSouth(int* dice) {
	int temp = dice[south]; //south
	dice[south] = dice[top];//top→south
	dice[top] = dice[north];//north → south
	dice[north] = dice[bottom];	//bottom → north
	dice[bottom] = temp; //south→bttom
	return;
}
int main() {
	int n, m;//지도의 세로, 가로 크기
	int x, y;//주사위를 놓은 곳의 좌표 x,y
	int k;//명령의 개수
	int map[20][20], order[1001];
	int dice[6] = { 0,0,0,0,0,0 }; //1234동서북남 0top 5bottom 을 가리키는 면에 있는 숫자
	int add[4][2] = { {0,1},{0,-1},{-1,0},{1,0} };

	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}
	for (int i = 0; i < k; i++)
		cin >> order[i];

	for (int i = 0; i < k; i++) {
		// 주사위 위치 업데이트
		if (x + add[order[i] - 1][0] >= n || x + add[order[i] - 1][0] < 0)
			continue;
		if (y + add[order[i] - 1][1] >= m || y + add[order[i] - 1][1] < 0)
			continue;
		x += add[order[i] - 1][0];
		y += add[order[i] - 1][1];

		// 주사위 방위정보 업데이트
		switch (order[i]) {
		case 1://east
			moveEast(dice);
			break;
		case 2://west
			moveWest(dice);
			break;
		case 3://north
			moveNorth(dice);
			break;
		case 4://south
			moveSouth(dice);
			break;
		}
		//칸이 0이면 주사위→칸, 아니면 칸→주사위, 칸 증발
		if (map[x][y] == 0)
			map[x][y] = dice[bottom];
		else {
			dice[bottom] = map[x][y];
			map[x][y] = 0;
		}
		cout << dice[top] << '\n';
	}
}