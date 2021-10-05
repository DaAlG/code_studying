import java.io.*;
import java.util.*;

public class BJ_퇴사_14501 {
	
	static int N;
	static int[] T, P, dp;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		// 입력 처리
		N = Integer.parseInt(br.readLine());
		T = new int[N+1];
		P = new int[N+1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken());
			P[i] = Integer.parseInt(st.nextToken());
		}
		dp = new int[N+2];
		for (int i = N; i > 0; i--) {
			if(i+T[i] <= N+1) {
				dp[i] = Math.max(dp[i+T[i]]+P[i], dp[i+1]);
			}
			else dp[i] = dp[i+1];
		}
		
		System.out.println(dp[1]);
	}

}
