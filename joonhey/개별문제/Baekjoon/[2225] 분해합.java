import java.util.*;

class Main{
	static int N, K;
	static int[][] dp;
	static final int MOD = 1000000000;
	
//		기본 값 초기화
	public static int solution() {
//		모든 정수를 정수 하나로 만드는 방법은 모두 한가지임
		if(K == 1 )
			return 1;
		
		for(int i=0; i<=N; i++) {
			dp[1][i] = 1;
		}
		for(int i=1; i<K; i++) {
			dp[i][0] = 1;
		}

		for(int n = 1; n <=N; n++) {
//			0~ n을 만들기 위해 정수를 k-1개 만큼 사용했을 때와 같음
//			0 + N, 1 + (N-1) , ..이렇게 숫자를하나 더해서 K개를 만들면 되니까
			for(int k=2; k<K; k++) {
				for(int d=0; d<=n; d++)
					dp[k][n]  = (dp[k][n] + dp[k-1][d]) % MOD;
			}
		}
//		최종 답 구하깅.
		int res = 0;
		for(int n=0; n<=N; n++)
			res  = (res + dp[K-1][n]) % MOD;
			
		
		return res;
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		K = sc.nextInt();
		dp = new int[K][N+1];
		System.out.println(solution());
	}

}