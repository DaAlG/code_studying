import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
 
class Solution{
    static int N;
    static char[][] arr;
    static int res;
    static boolean[][] visited;
    static int[] di = {-1,-1,-1,0,0,1,1,1};
    static int[] dj = {-1,0,1,-1,1,-1,0,1};
    static Queue<Point> queue;
    
    static class Point{
    	int x; int y;
    	public Point(int x, int y) {
    		this.x = x;
    		this.y = y;
    	}
    }
    public static void bfs() {
        int ni, nj;
         
        while(!queue.isEmpty()) {
            Point cur= queue.poll();
            int curX = cur.x;
            int curY = cur.y;
//          현재위치부터 8방위 방문.
            int d = 0;
            for(d=0; d<8; d++) {
                ni = curX + di[d];
                nj = curY + dj[d];
                if(ni >= 0 && ni < N && nj >= 0 && nj < N && arr[ni][nj] == '*')
                    break;
            }
            if( d == 8) { //그 위치부터 범위 내 방문.
                for(int k = 0; k<8; k++) {
                    ni = curX + di[k];
                    nj = curY + dj[k];
                    if(ni >= 0 && ni < N && nj >= 0 && nj < N && !visited[ni][nj]) {
                        visited[ni][nj] = true;
                        queue.offer(new Point(ni, nj));
                    }
                }
            }
            //지뢰 근처에 있으면 방문 x
             
        }
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        int T;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder("");
        queue = new LinkedList<>();
         
        for(int t= 1; t<=T ;t++) {
            res = 0;
            N = Integer.parseInt(br.readLine());
            //맵 입력
            arr = new char[N][N];
            visited = new boolean[N][N];
            String inputLine;
            for(int i=0; i<N; i++) {
                inputLine = br.readLine();
                for(int j=0; j<N; j++) {
                    arr[i][j] = inputLine.charAt(j);
                    if(arr[i][j] == '*')
                        visited[i][j] = true;
//                  지뢰들은 방문할 필요 x 
//                  visited[i][j] == false인 곳을 지뢰가 없고, 하나씩 클릭해줘야하는 곳으로 판단하기 위함.
                }
            }
            int ni, nj;
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(arr[i][j] == '.' && !visited[i][j]) {
//                      8방향 탐색 후 주위에 지뢰가 없으면 큐에 삽입 후 bfs
                        int d = 0;
                        for(d=0; d<8; d++) {
                            ni = i + di[d];
                            nj = j + dj[d];
//                          범위 밖이면 무시 ㄱㄴ. 범위 내의 지뢰만 신경쓰자
                            if(ni >= 0 && ni < N && nj >= 0 && nj < N && arr[ni][nj] == '*') {
                                break;
                            }
                        }
                        if (d == 8 && !visited[i][j]) { //bfs 시작.
                            res++;
                            visited[i][j] = true;
                            queue.offer(new Point(i, j));
                            bfs();
                        }
                    }
                }
            }
            //주위 지뢰가 없는 칸 중심으로 확장 완료.. 나머지는 따로따로 눌러줘야 되는 애들.
            for(int i=0; i<N; i++) {
                for(int j=0; j<N; j++) {
                    if(!visited[i][j])
                        res++;
                }
            }
             
            sb.append("#").append(t).append(" ").append(res).append("\n");
        }
        System.out.println(sb);
         
    }
}