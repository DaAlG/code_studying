package day0323;

import java.util.Scanner;

//1. dfs로 터뜨리기
//2. dp로 안터뜨리기
public class Main {
	static int minCount;

	public static void dfs(int n, int cnt) {
		// 기저
		if (n == 1) {
			if (cnt < minCount)
				minCount = cnt;
			return;
		}
		if (n < 1)
			return;

		// 반복
		if (cnt % 3 == 0) {
			dfs(n / 3, cnt + 1);
		}
		if (cnt % 2 == 0) {
			dfs(n / 2, cnt + 1);
		}

		dfs(n - 1, cnt + 1);

	}

	public static void dp(int n) {

		int[] arr = new int[n + 1];
		//기저 f(1) = 0;
		arr[1] = 0; //1은 도착점이므로 count x
		int i = 2;
		while( i != n + 1) { //겅중 겅중
			int a = Integer.MAX_VALUE; 
			if(i % 3 == 0)
				a = arr[i/3] + 1; 
			if(i % 2 == 0)
				a = arr[i/2] + 1 <= a ? arr[i/2]+1 : a;
			a = a <= arr[i-1] + 1 ? a : arr[i-1]+1;
			//세 개 중 가장 작은 값.
			arr[i] = a; 
			i++;
		}
		
		minCount = arr[n];
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		minCount = Integer.MAX_VALUE;
//		dfs(n, 0);
		dp(n);
		System.out.println(minCount);
	}
}
