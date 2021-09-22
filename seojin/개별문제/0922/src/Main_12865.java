// 12865 평범한 배낭 - knapsack 전형적인 문제..!!

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main_12865 {
	
	static int N, K;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		
		st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		int[] weights = new int[N+1];
		int[] profits = new int[N+1];
		
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			weights[i] = Integer.parseInt(st.nextToken()); // 무게
			profits[i] = Integer.parseInt(st.nextToken()); // 가치
		}
		
		int[][] D = new int[N+1][K+1];
		for (int i = 1; i <= N; i++) {
			for (int w = 1; w <= K; w++) {
				if(weights[i] <= w) { // 해당 물건을 가방에 넣을 수 있다.
					D[i][w] = Math.max(D[i-1][w], D[i-1][w-weights[i]] + profits[i]);
				}else {// 해당 물건을 가방에 넣을 수 없다.(가방 용량보다 물건이 커서)
					D[i][w] = D[i-1][w]; // 직전물건까지의 최적의 가치가 그대로 들어옴
				}
			}
		}
		
		System.out.println(D[N][K]);
	}
}

