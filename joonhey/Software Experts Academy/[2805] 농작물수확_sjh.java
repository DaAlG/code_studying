import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
public class Solution {
    static int res;
    static char[][] farm = new char[49][49];
    static int N;
    public static void harvestUpward(int row, int startIdx, int endIdx) {
        if(row == -1 ) 
            return;
        for(int i = startIdx; i<= endIdx; i++) {
            res += farm[row][i] - '0';
        }
        harvestUpward(row - 1, startIdx + 1, endIdx - 1);
    }
    public static void harvestDownward(int row, int startIdx, int endIdx) {
        if(row == N) 
            return;
        for(int i = startIdx; i<= endIdx; i++) {
            res += farm[row][i] - '0';
        }
        harvestDownward(row + 1, startIdx + 1, endIdx - 1);
    }
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        String inputLine;
        int halfRow;
        for (int t = 0; t < T; t++) {
            res = 0;
            N = Integer.parseInt(br.readLine());
            halfRow = N / 2;
            for (int i = 0; i < N; i++) {
                inputLine = br.readLine();
                for (int j = 0; j < N; j++) {
                    farm[i][j] = inputLine.charAt(j);
                }
            }
            for (int j = 0; j < N; j++) {
                res += farm[halfRow ][j] - '0';
            }
            harvestUpward(halfRow - 1, 1, N - 2);
            harvestDownward(halfRow + 1, 1, N - 2);
            System.out.println("#" + (t + 1) + " "+res);
        }
    }
}