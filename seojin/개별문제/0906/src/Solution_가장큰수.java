import java.util.*;

public class Solution_가장큰수 {

    public static String solution(int[] numbers) {
        String answer = "";
        
        for(int n : numbers) {
        	answer += n;
        }
        
        char[] ans = answer.toCharArray();
        Arrays.sort(ans);
        
        StringBuilder sb = new StringBuilder();
        for (int i = ans.length-1; i>=0; i--) {
			sb.append(ans[i]);
		}
        
     
        return sb.toString();
    }
    
    public static void main(String[] args) {
		solution(new int[]{6,10,2});
	}

}
