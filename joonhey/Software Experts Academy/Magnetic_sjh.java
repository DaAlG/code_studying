import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static short[][] map;
    static int deadlock;
    static boolean[][] visited;
    static int N;
     
    public static void scanDownward(int startX, int startY) {
        visited[startX][startY] = true; //중복 방지.
         
        for(int i=startX; i<N; i++) {
            if(map[i][startY] == 2 && !visited[i][startY]) {
                deadlock++;
                visited[i][startY] = true;
                break;
            }
            else if(map[i][startY] == 1 && !visited[i][startY])
                visited[i][startY] = true;
        }
    }
    //위 방향 스캔 후 1 있나 찾기.
    public static void scanUpward(int startX, int startY) {
        visited[startX][startY] = true; //중복 방지.
         
        for(int i=startX; i>=0; i--) {
            if(map[i][startY] == 1 && !visited[i][startY]) {
                deadlock++;
                visited[i][startY] = true;
                break;
            }
            else if(map[i][startY] == 2 && !visited[i][startY])
                visited[i][startY] = true;
        }
    }
    public static void scanTable() {
        for(int i=0;i<N; i++) {
            for(int j=0; j<N; j++) {
                if(map[i][j] == 1 && !visited[i][j])
                    scanDownward(i, j); //i행 j열 아래 스캔
                else if(map[i][j] == 2 && !visited[i][j])
                    scanUpward(i, j); //i행 j열 위 스캔
                 
            }
        }
    }
     
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        for(int t=0; t<10; t++) {
            deadlock = 0;
            N = Integer.parseInt(br.readLine());
            map = new short[N][N];
            visited = new boolean[N][N];
            for(int i=0; i<N; i++) {
                st = new StringTokenizer(br.readLine());
                for(int j=0; j<N; j++) {
                    map[i][j] = Short.parseShort(st.nextToken());
                }
            }
            scanTable(); 
            System.out.println("#"+(t+1)+" "+deadlock);
        }
    }
}