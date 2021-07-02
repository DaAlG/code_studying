package project;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Main {
	static int[] arr;
	static int N;
	static int res;
	static int[][] dp;
	
	public static int getResult(int left, int right) {
//		값 재활용
		if(dp[left][right] != -1)
			return dp[left][right];
//		기저 조건
		if(left == right)
			return dp[left][right] = 0;
		
		if(left == right -1) {
			if(arr[left] != arr[right])
				return dp[left][right] = 1;
			else
				return dp[left][right] = 0;
		}
		if(arr[left] == arr[right]) {
			return dp[left][right] = getResult(left+1, right-1);
		}
		else {
//			왼쪽 기준으로 맞추기, 오른쪽 기준으로 맞추기
			int l = getResult(left+1, right);
			int r = getResult(left, right-1);
			return dp[left][right] = l < r ? l + 1: r + 1;
		}
	}
	
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		arr = new int[N];
		dp = new int[N][N];
		for (int i = 0; i < N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dp[i][j] = -1;
		
		System.out.println(getResult(0,N-1));
	}
}