using namespace std;
#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <tuple>
#include <algorithm>

typedef tuple<int, int, int> shark; // (����ȣ, ��ġ x, ��ġ y)

int n, m, k; // N ������ ũ��, M ����� ��, K ��� ���� �ð�
vector<shark> sharks;
int scent[2][20][20]; //[0]���� ����� ī��Ʈ, [1]���� ����� ����
int board[2][20][20]; //���� ����� ��ȣ�� ����
int nextBoard[2][20][20]; //���� ����� ��ȣ�� ����
int pq[401][5][5]; //[����ȣ][�������][�������� �켱������]
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
//�� �Ʒ� ���� ������ 

bool inRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void move_shark() { // nextBoard ������ �ٲ۴�.
	int size = sharks.size();
	vector<int> toDelete;
	for (int i = 0; i < size; i++) {
		bool done = false;
		int num, x, y;
		tie(num, x, y) = sharks[i];
		int cur_dir = board[1][x][y];

		//��Ⱑ ���� ���̸� �̵�
		for (int j = 1; j <= 4; j++) {
			int next_dir = pq[num][cur_dir][j];
			int nx = x + dx[next_dir];
			int ny = y + dy[next_dir];

			if (!inRange(nx, ny)) continue;
			if (scent[0][nx][ny] == 0) {
				done = true;
				if (nextBoard[0][nx][ny] != 0) { //�̹� ������ �� �ִٸ� �Ѱܳ�
					toDelete.push_back(i);
					break;
				}
				nextBoard[0][nx][ny] = num;
				nextBoard[1][nx][ny] = next_dir;
				sharks[i] = make_tuple(num, nx, ny);
				break;
			}
		}
		if (done == true) continue;
		//��Ⱑ ���� ���� ���ٸ� �ڱ� ��� �ִ� ������ �̵�
		for (int j = 1; j <= 4; j++) {
			int next_dir = pq[num][cur_dir][j];
			int nx = x + dx[next_dir];
			int ny = y + dy[next_dir];

			if (!inRange(nx, ny)) continue;
			if (scent[1][nx][ny] == num) {
				nextBoard[0][nx][ny] = num;
				nextBoard[1][nx][ny] = next_dir;
				sharks[i] = make_tuple(num, nx, ny);
				done = true;
				break;
			}
		}
		if (done == false) {
			nextBoard[0][x][y] = num;
			nextBoard[1][x][y] = cur_dir;
		}
	}
	while (!toDelete.empty()) {
		sharks.erase(sharks.begin() + toDelete.back());
		toDelete.pop_back();
	}
}

void update() {
	//��� ������Ʈ
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (nextBoard[0][i][j] != 0) {
				scent[0][i][j] = k;
				scent[1][i][j] = nextBoard[0][i][j];
			}
			else if(scent[0][i][j]!=0) {
				if (--scent[0][i][j] == 0)
					scent[1][i][j] = 0;
			}
		}
	}
	memcpy(board, nextBoard, sizeof(board));
	memset(nextBoard, 0, sizeof(nextBoard));
}
int solve() { //1�� �� Ȧ�� ������� �ɸ��� �ð�
	int ans = 0;
	while (sharks.size() > 1 && ans <= 1000) {
		move_shark();
		update();
		ans++;
	}
	if (ans > 1000) return -1;
	return ans;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0, w; j < n; j++) {
			cin >> board[0][i][j];
			if (board[0][i][j] != 0) {
				sharks.push_back(make_tuple(board[0][i][j], i, j));
				scent[0][i][j] = k;
				scent[1][i][j] = board[0][i][j];
			}
		}
	}

	sort(sharks.begin(), sharks.end()); // �� �������� ����
	//���� ����
	for (int i = 0; i < sharks.size(); i++) {
		int num, x, y;
		tie(num, x, y) = sharks[i];
		cin >> board[1][x][y];
	}

	
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= 4; j++)
			for (int h = 1; h <= 4; h++)
				cin >> pq[i][j][h];

	cout<<solve()<<'\n';
}