package project;

import java.io.BufferedReader;
import java.io.InputStreamReader;

class Main{
	static int N;
	static int[] arr;
	static int[] dp;
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		dp = new int[N];
		
		for(int i=0; i<N; i++) {
			arr[i] = Integer.parseInt(br.readLine());
		}
		//초기화
		dp[0] = arr[0];
		
		for(int i=1; i<N; i++) {
			//이전것도 같이 선택할 경우 -> 두번째 전 건 무조건 선택 안함
			dp[i] = i >=3 ? arr[i] + arr[i-1] + dp[i-3] : arr[i] + arr[i-1];
			//이전건 선택 x -> 두번째 꺼 관심 x
			dp[i] = i != 1 ? (dp[i] > dp[i-2] + arr[i] ? dp [i] : dp[i-2] + arr[i]):(dp[i] > arr[i] ? dp[i] : arr[i]);
			//현재 원소 선택하지 않을 경우
			dp[i] = dp[i-1] < dp[i] ? dp[i] : dp[i-1];
		}
//		for(int d : dp)
//			System.out.println(d);
		System.out.println(dp[N-1]);
	}
	
}