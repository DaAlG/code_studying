package BOJ.BOJ_21317;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// BOJ 21317 징검다리 건너기
public class Main {
	
	private static int n;
	private static int k;
	private static int[][] energy;
	private static int[][] dp;
	
	private static void go(int now, int flag) {
		if (now == n - 1) return;
		
		if (now + 1 < n) { // 작은 점프
			dp[now + 1][flag] = Math.min(dp[now + 1][flag], dp[now][flag] + energy[now][0]);
			go(now + 1, flag);
		}
		
		if (now + 2 < n) { // 큰 점프
			dp[now + 2][flag] = Math.min(dp[now + 2][flag], dp[now][flag] + energy[now][1]);
			go(now + 2, flag);
		}
		
		if (flag == 0 && now + 3 < n) { // 매우 큰 점 프는 한 번만 가능
			dp[now + 3][1] = Math.min(dp[now + 3][1], dp[now][flag] + k);
			go(now + 3, 1);
		}
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		n = Integer.parseInt(br.readLine());
		energy = new int[n][2];
		dp = new int[n][2];
		for (int i = 0; i < energy.length; i++) {
			if (i < n - 1) {
				String[] input = br.readLine().split(" ");
				energy[i][0] = Integer.parseInt(input[0]);
				energy[i][1] = Integer.parseInt(input[1]);
			}
			dp[i][0] = dp[i][1] = 100000;
		}
		k = Integer.parseInt(br.readLine());
		
		dp[0][0] = dp[0][1] = 0;
		go(0, 0);
		System.out.println(Math.min(dp[n - 1][0], dp[n - 1][1]));
		
	}

}
