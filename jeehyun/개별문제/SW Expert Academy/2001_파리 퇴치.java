import java.util.Scanner;

// SWEA 2001 파리 퇴치
public class Solution {
	private static int n;
	private static int m;
	private static int[][] arr;
	
	private static int getSum(int x, int y) {
		int sum = 0;
		for (int i = x; i < x + m; i++) {
			for (int j = y; j < y + m; j++) {
				sum += arr[i][j];
			}
		}
		return sum;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for (int test_case = 1; test_case <= T; test_case++) {
			n = sc.nextInt();
			m = sc.nextInt();
			
			arr = new int[n][n];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					arr[i][j] = sc.nextInt();
				}
			}
			
			int answer = 0;
			for (int i = 0; i < n; i++) {
				if (i + m > n) break;
				for (int j = 0; j < n; j++) {
					if (j + m > n) break;
					answer = Math.max(answer, getSum(i, j));
				}
			}
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
