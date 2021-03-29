package day0323;

import java.util.Scanner;

//1. dfs로 안터뜨리기 - 가지치기, 호출 횟수 줄이기를 해야 속도가 줄어듦.

public class Main {
	static int minCount;
	static int[] num;

	public static void dfs(int n, int cnt) {
		// 기저
		if (n == 1) {
			// 기록
			num[n] = cnt;
			minCount = num[1];
			return;
		}
		// 기록
		num[n] = cnt;

		// 반복
		if (n % 3 == 0 && (num[n / 3] == 0 || num[n / 3] > cnt + 1)) {
			dfs(n / 3, cnt + 1);
		}
		if (n % 2 == 0 && (num[n / 2] == 0 || num[n / 2] > cnt + 1)) {
			dfs(n / 2, cnt + 1);
		}
		if (num[n - 1] == 0 || num[n - 1] > cnt + 1)
			dfs(n - 1, cnt + 1);

	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		num = new int[n + 1];
		minCount = Integer.MAX_VALUE;
		dfs(n, 0);
		System.out.println(minCount);
	}
}