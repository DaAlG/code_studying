
import java.util.*;

// 파스칼의 삼각형으로 풀어야한다..
// next permutation 배웠다고 나대다 망함..ㅋㅋ..
public class Main_11051 {
	
	static int N, K;
	static long CNT;
	static int[] src;
	static int[] tgt;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		
		
		int[][] dp = new int[N+1][N+1];
		
		for (int i = 0; i < dp.length; i++) {
			for (int j = 0; j <=i; j++) {
				if(i==j || j==0) dp[i][j] = 1;
				else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % 10007;
			}
		}
		
		
		System.out.println(dp[N][K]);

	}
}
