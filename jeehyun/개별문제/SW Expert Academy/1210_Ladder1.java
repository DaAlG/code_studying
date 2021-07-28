import java.util.Scanner;
 
class Solution {
    static int n = 100;
    static int map[][] = new int[n][n];
     
    public static int solve(int y) {
        int x = n - 1;
        while (x-- != 0) {
            boolean check = false;
             
            if (y + 1 < n && map[x][y + 1] == 1) {
                check = true;
                while (y + 1 < n && map[x][y + 1] == 1) y++;
            }
             
            if (!check) {
                while ((y - 1 >= 0) && map[x][y - 1] == 1) y--;
            }
        }
        return y;
    }
     
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T = 10;
         
        for(int test_case = 1; test_case <= T; test_case++) {
            test_case = sc.nextInt();
             
            int y = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = sc.nextInt();
                    if (map[i][j] == 2) {
                        y = j;
                    }
                }
            }
            System.out.println("#" + test_case + " " + solve(y));
        }
    }
}