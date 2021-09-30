import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ_퇴사2_15486 {

	static int N;
	static int[] T, P, dp;
	
	public static void main(String[] args) throws Exception{
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		N = Integer.parseInt(br.readLine());
		T = new int[N+2]; // N+1번째까지 고려
		P = new int[N+2];
		dp = new int[N+2];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			T[i] = Integer.parseInt(st.nextToken());
			P[i] = Integer.parseInt(st.nextToken());
		}
		
		for (int i = N; i > 0; i--) {
			if(i+T[i] > N+1) dp[i] = dp[i+1]; // N일 초과하면 그 다음날 거 그대로
			else dp[i] = Math.max(dp[i+1], P[i] + dp[i+T[i]]); // 아니라면 비교
		}
		
		System.out.println(dp[1]);
	}
}
