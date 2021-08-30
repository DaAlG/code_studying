import java.util.Scanner;

// SWEA 1948 날짜 계산기
class Solution {
	private static int[] days = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		
		for (int test_case = 1; test_case <= T; test_case++) {
			int m1 = sc.nextInt();
			int d1 = sc.nextInt();
			int m2 = sc.nextInt();
			int d2 = sc.nextInt();
			
			int answer = 0;
			if (m1 == m2) {
				answer = d2 - d1 + 1;
			} else {
				answer = days[m1] - d1 + 1;
				for (int i = m1 + 1; i < m2; i++) {
					answer += days[i];
				}
				answer += d2;
			}
			
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
