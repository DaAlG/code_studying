#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n, k, l;
int board[101][101];
bool loc[101][101];
vector<pair<int, char>> dir;
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > n)
        return false;
    return true;
}

int go(int x, int y)
{
    deque<pair<int, int>> snake;
    loc[x][y] = true;
    snake.push_front(make_pair(x, y));

    int sec = 1;
    int cur = 0;
    int d = 0;

    while (!snake.empty()) {
        
        int nx = snake.front().first + dx[d];
        int ny = snake.front().second + dy[d];

        // 뱀의 방향 변환 정보 확인
        if (cur < dir.size() && sec == dir[cur].first) {
            // L이면 왼쪽으로 90도 방향 회전
            if (dir[cur].second == 'L')
                d = (--d < 0) ? 3 : d;
            else // D이면 오른쪽으로 90도 방향 회전
                d = (++d > 3) ? 0 : d;
            cur++;
        }
        
        // 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다
        if (!check(nx, ny) || loc[nx][ny])
            break;

        // 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다
        if (board[nx][ny]) {
            board[nx][ny] = 0;
            
        }
        else { // 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다
            pair<int, int> tail = snake.back();
            loc[tail.first][tail.second] = false;
            snake.pop_back();
        }
        loc[nx][ny] = true;
        snake.push_front(make_pair(nx, ny));
        
        sec++;
    }

    return sec;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    char ch;
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        board[a][b] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> a >> ch;
        dir.push_back(make_pair(a, ch));
    }

    cout << go(1, 1);
    return 0;
}