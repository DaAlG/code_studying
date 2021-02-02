import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
 
public class Solution {
    static boolean[][] visited;
    public static void main(String[] args) throws NumberFormatException, IOException {
        short[][] map = new short[100][100];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        int curi = 0;
        int curj = 0;
        int ni = 0;
        int nj = 0;
        int[] di = { 0, 0, -1 };
        int[] dj = { -1, 1, 0 };
        for (int t = 0; t < 10; t++) {
            visited = new boolean[100][100];
            br.readLine(); 
            short input;
            for (int i = 0; i < 100; i++) {
                st = new StringTokenizer(br.readLine(), " ");
                for (int j = 0; j < 100; j++) {
                    input = Short.parseShort(st.nextToken());
                    map[i][j] = input;
                    if (input == 2) {
                        curi = i;
                        curj = j;
                    }
                }
            }
            while(curi != 0) {
                visited[curi][curj] = true;
                for(int k=0; k<3; k++) {
                    ni = curi + di[k];
                    nj = curj + dj[k];
                    if(nj<0 || nj >=100) continue;
                    if(map[ni][nj] == 0) continue;
                    if(visited[ni][nj]) continue;
                    break;
                }
                curi = ni;
                curj = nj;
            }
            System.out.println("#" + (t + 1) + " " + curj);
        }
    }
}