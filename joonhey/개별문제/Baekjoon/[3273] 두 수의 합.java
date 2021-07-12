package project;

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main{
	static int N;
	static int[] arr;
	static int res;
	
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));	
		N = Integer.parseInt(br.readLine());
		arr = new int[N];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i=0; i<N; i++)
			arr[i] = Integer.parseInt(st.nextToken());
		int num = Integer.parseInt(br.readLine());
		
		Arrays.sort(arr);
	
		int l = 0;
		int r = N-1;
		
		while(l < r) {
			int sum = arr[l] + arr[r];
			if(sum == num) {
				res++;
				l++;
				r--;
			}
			else if(sum > num) {
				r--;
			}else {
				l++;
			}
		}
		System.out.println(res);
	}
}