import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
 
class Solution {
    public static void main(String[] args) throws NumberFormatException, IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
 
        for (int t = 0; t < T; t++) {
            String input = br.readLine();
            int checkBit = 0;
            int cnt = 0;
            for(int i = 0; i<input.length(); i++) {
                if(input.charAt(i)-'0' != checkBit) {
                    cnt++;
                    checkBit = (checkBit+1) % 2;
                }
            }
 
            System.out.println("#" + (t + 1) + " " + cnt);
        }
    }
}