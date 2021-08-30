import java.util.Scanner;
 
public class Solution_4615 {
    // IM Prac
    static int T, N, M;
    static int[][] map;
    // 좌상 상 우상 우 우하 하 좌하 좌 
    static int[] dx = { -1, -1, -1, 0, 1, 1, 1, 0};
    static int[] dy = {-1, 0, 1, 1, 1, 0, -1, -1};
    public static void main(String[] args) {
 
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();
 
        for (int t = 1; t <= T; t++) {
 
            N = sc.nextInt();
            M = sc.nextInt();
            map = new int[N+1][N+1];
 
            // 초기 배치
            map[N/2][N/2] = map[N/2 +1][N/2 +1] = 2;    // 백
            map[N/2][N/2 +1] = map[N/2 +1][N/2] = 1;    // 흑
 
             
            for (int m = 0; m < M; m++) {
                int y = sc.nextInt();
                int x = sc.nextInt();
                int c = sc.nextInt();   // 1 2 1 
 
                map[x][y] = c;
                othello(x,y,c);
                 
            }
            System.out.println("#" + t + " " + result());
 
        } 
         
    }
 
    public static String result() {
        int[] ans = new int[2];
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if(map[i][j] == 1) ans[0]++;
                else if(map[i][j] == 2) ans[1]++;
            }
        }
        return ans[0] + " " + ans[1];
    }
 
    public static void othello(int x, int y, int c) {
 
        for (int d = 0; d < 8; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
 
            //boolean check = false;        // nx ny가 내 돌인지 체크해보려구
            while(true) {
                // nx가 map범위 밖이거나 0이면 비교할 필요 없음 break
                if(!isCheck(nx, ny) || map[nx][ny] ==0) break;
 
                // 8방 조사 후, 다른 돌이면 
                if(map[nx][ny] != map[x][y]) {
                    // 이제 같은 돌을 찾아야함  ( 같은 돌 찾으면 그 사이 돌 c로 바꿔줘야함 ) 
                    nx += dx[d];    // 같은 방향으로 이동해서 찾을거니까
                    ny += dy[d];
                }else break;    // 같은 돌이면 나가자
            }
 
            // 다시 범위 체크하고 같은 색인 위치 찾았으면
            if(isCheck(nx,ny) && map[nx][ny] == c ){    // c = map[x][y]
                // 지금 방향으로 -시키면서 x ==nx나 y==ny 될 때까지 돌리고 색 변경
                while(x != nx || y != ny) {
                    map[nx][ny] = c;
                    nx -= dx[d];
                    ny -= dy[d];
                }
 
            }
        }
    }
 
    public static boolean isCheck(int x, int y) {
        return x >0 && x <=N && y >0 && y <=N;
    }
 
}